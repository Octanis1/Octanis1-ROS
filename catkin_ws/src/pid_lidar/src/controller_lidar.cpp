/***************************************************************************//**
* \file controller.cpp
*
* \brief Simple PID controller with dynamic reconfigure and diagnostics
* \author Andy Zelenak
* \date March 8, 2015
*
* \section license License (BSD-3)
* Copyright (c) 2015, Andy Zelenak\n
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
* - Redistributions of source code must retain the above copyright notice,
* this list of conditions and the following disclaimer.
* - Redistributions in binary form must reproduce the above copyright notice,
* this list of conditions and the following disclaimer in the documentation
* and/or other materials provided with the distribution.
* - Neither the name of Willow Garage, Inc. nor the names of its contributors
* may be used to endorse or promote products derived from this software
* without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
******************************************************************************/

// Subscribe to a topic about the state of a dynamic system and calculate feedback to
// stabilize it.

#include <pid/controller_lidar.h>
//#include <pid/PidConfig.h>

//#include <dynamic_reconfigure/server.h>
#include <ros/time.h>

void plant_state_callback(const std_msgs::UInt16& state_msg)
{
  if (state_msg.data < 600) // To avoid blown up values
  {
  if ( !((Kp<=0. && Ki<=0. && Kd<=0.) || (Kp>=0. && Ki>=0. && Kd>=0.)) ) // All 3 gains should have the same sign
  {
    ROS_WARN("All three gains (Kp, Ki, Kd) should have the same sign for stability.");
  }

  plant_state = state_msg.data;

  error.at(2) = error.at(1);
  error.at(1) = error.at(0);
  error.at(0) = setpoint - plant_state; // Current error goes to slot 0

  //..... reset error if it saturates .....
  if ((error.at(0)>=max_error) && (error.at(1)>=max_error) && (error.at(2)>=max_error))
  {
    error.at(0) = 0.0;
    error.at(1) = 0.0;
    error.at(2) = 0.0; 
    ROS_INFO("Error reset");
  }
  // ......

  // calculate delta_t
  if (!prev_time.isZero()) // Not first time through the program  
  {
    delta_t = ros::Time::now() - prev_time;
    prev_time = ros::Time::now();
    if (0 == delta_t.toSec())
    {
      ROS_ERROR("delta_t is 0, skipping this loop. Possible overloaded cpu at time: %f", ros::Time::now().toSec());
      return;
    }
  }
  else
  {
    ROS_INFO("prev_time is 0, doing nothing");
    prev_time = ros::Time::now();
    return;
  }

  // integrate the error
  error_integral += error.at(0) * delta_t.toSec();

  // Apply windup limit to limit the size of the integral term
  if ( error_integral > fabsf(windup_limit))
    error_integral = fabsf(windup_limit);

  if ( error_integral < -fabsf(windup_limit))
    error_integral = -fabsf(windup_limit);

  // My filter reference was Julius O. Smith III, Intro. to Digital Filters With Audio Applications.
  if (cutoff_frequency != -1)
  {
    // Check if tan(_) is really small, could cause c = NaN
    tan_filt = tan( (cutoff_frequency*6.2832)*delta_t.toSec()/2 );

    // Avoid tan(0) ==> NaN
    if ( (tan_filt<=0.) && (tan_filt>-0.01) )
      tan_filt = -0.01;
    if ( (tan_filt>=0.) && (tan_filt<0.01) )
      tan_filt = 0.01;

    c = 1/tan_filt;
  }

  filtered_error.at(2) = filtered_error.at(1);
  filtered_error.at(1) = filtered_error.at(0);
  filtered_error.at(0) = (1/(1+c*c+1.414*c))*(error.at(2)+2*error.at(1)+error.at(0)-(c*c-1.414*c+1)*filtered_error.at(2)-(-2*c*c+2)*filtered_error.at(1));

  // Take derivative of error
  // First the raw, unfiltered data:
  error_deriv.at(2) = error_deriv.at(1);
  error_deriv.at(1) = error_deriv.at(0);
  error_deriv.at(0) = (error.at(0)-error.at(1))/delta_t.toSec();

  filtered_error_deriv.at(2) = filtered_error_deriv.at(1);
  filtered_error_deriv.at(1) = filtered_error_deriv.at(0);

  if ( loop_counter>2 ) // Let some data accumulate
    filtered_error_deriv.at(0) = (1/(1+c*c+1.414*c))*(error_deriv.at(2)+2*error_deriv.at(1)+error_deriv.at(0)-(c*c-1.414*c+1)*filtered_error_deriv.at(2)-(-2*c*c+2)*filtered_error_deriv.at(1));
  else
    loop_counter++;

  // calculate the control effort
  proportional = Kp * filtered_error.at(0);
  integral = Ki * error_integral;
  derivative = Kd * filtered_error_deriv.at(0);
  control_effort = proportional + integral + derivative;

  // Apply saturation limits
  if (control_effort > upper_limit)
  {
    control_effort = upper_limit;
    diag_status.level = diagnostic_msgs::DiagnosticStatus::WARN;
    diag_status.message = "Control effort exceeded upper limit";
  }
  else if (control_effort < lower_limit)
  {
    control_effort = lower_limit;
    diag_status.level = diagnostic_msgs::DiagnosticStatus::WARN;
    diag_status.message = "Control effort exceeded lower limit";
  }
  else
  {
    diag_status.level = diagnostic_msgs::DiagnosticStatus::OK;
    diag_status.message = "PID controller nominal";
  }

  // Publish the stabilizing control effort if the controller is enabled
  if (pid_enabled)
  {
    control_msg.data = control_effort;
    control_effort_pub.publish(control_msg);
  }
  else
  {
    error_integral = 0.0;
    diag_status.level = diagnostic_msgs::DiagnosticStatus::ERROR;
    diag_status.message = "PID controller disabled";
  }
  }
  // update diags
  ++measurements_received;
  diags->freq_status.tick();
  diags->diag_updater.update();

  return;
}

void pid_enable_callback(const std_msgs::Bool& pid_enable_msg)
{
  pid_enabled = pid_enable_msg.data;
}


void get_pid_diag_status(diagnostic_updater::DiagnosticStatusWrapper& pid_diag_status)
{
  pid_diag_status.summary(diag_status);
  pid_diag_status.add("Setpoint", setpoint);
  pid_diag_status.add("Plant State", plant_state);
  pid_diag_status.add("Control Error", error.at(0));
  pid_diag_status.add("Control output effort", control_effort);
  pid_diag_status.add("Proportional effort", proportional);
  pid_diag_status.add("Integral effort", integral);
  pid_diag_status.add("Derivative effort", derivative);
  pid_diag_status.add("Measurements received", measurements_received);
}

  ////////////////////////////////////
  // Error checking
  ////////////////////////////////////

bool validate_parameters()
{
  if ( lower_limit > upper_limit )
  {
    ROS_ERROR("The lower saturation limit cannot be greater than the upper saturation limit.");
    return(false);
  }

  return true;;
}

  ////////////////////////////////////
  // Display parameters
  ////////////////////////////////////
void print_parameters()
{
  std::cout<< std::endl<<"PID PARAMETERS"<<std::endl<<"-----------------------------------------"<<std::endl;
  std::cout << "Kp: " << Kp << ",  Ki: " << Ki << ",  Kd: " << Kd << std::endl;
  if ( cutoff_frequency== -1) // If the cutoff frequency was not specified by the user
    std::cout<<"LPF cutoff frequency: 1/4 of sampling rate"<<std::endl;
  else
    std::cout<<"LPF cutoff frequency: "<< cutoff_frequency << std::endl;
  std::cout << "pid node name: " << ros::this_node::getName() << std::endl;
  std::cout << "Name of topic from controller: " << topic_from_controller << std::endl;
  std::cout << "Name of topic from the plant: " << topic_from_plant << std::endl;
  std::cout << "Integral-windup limit: " << windup_limit << std::endl;
  std::cout << "Saturation limits: " << upper_limit << "/" << lower_limit << std::endl;
  std::cout << "-----------------------------------------" << std::endl;

  return;
}

////////////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
  ROS_INFO("Starting pid with node name %s", node_name.c_str());

  // Initialize ROS stuff
  ros::init(argc, argv, node_name);     // Note node_name can be overidden by launch file
  ros::NodeHandle node;
  ros::NodeHandle node_priv("~");

  while (ros::Time(0) == ros::Time::now())
  {
    ROS_INFO("controller spinning waiting for time to become non-zero");
    sleep(1);
  }

  // Get params if specified in launch file or as params on command-line, set defaults
  node_priv.param<double>("Kp", Kp, 1.0);
  node_priv.param<double>("Ki", Ki, 0.0);
  node_priv.param<double>("Kd", Kd, 0.0);
  node_priv.param<double>("upper_limit", upper_limit, 1000.0);
  node_priv.param<double>("lower_limit", lower_limit, -1000.0);
  node_priv.param<double>("windup_limit", windup_limit, 1000.0);
  node_priv.param<double>("max_error", max_error, 500.0);
  node_priv.param<double>("cutoff_frequency", cutoff_frequency, -1.0);
  node_priv.param<std::string>("topic_from_controller", topic_from_controller, "control_effort");
  node_priv.param<std::string>("topic_from_plant", topic_from_plant, "rpms");
  node_priv.param<double>("max_loop_frequency", max_loop_frequency, 1.0);
  node_priv.param<double>("min_loop_frequency", min_loop_frequency, 1000.0);

  // Update params if specified as command-line options, & print settings
  print_parameters();
  if (not validate_parameters())
  {
    std::cout << "Error: invalid parameter\n";
  }

  // instantiate publishers & subscribers
  control_effort_pub = node.advertise<std_msgs::Float64>(topic_from_controller, 1);

  ros::Subscriber sub = node.subscribe(topic_from_plant, 1, plant_state_callback );
  ros::Subscriber pid_enabled_sub = node.subscribe("pid_enable", 1, pid_enable_callback );


  // initialize diagnostics
  diags = new PidControllerDiags;

  diag_status.level = diagnostic_msgs::DiagnosticStatus::OK;
  diag_status.message = "PID status nominal";

  diags->diag_updater.setHardwareID(node_name);
  diags->diag_updater.add(diags->freq_status);
  diags->diag_updater.add("PID status", get_pid_diag_status);

  // Respond to inputs until shut down
  ros::spin();

  return 0;
}

