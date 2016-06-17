#include <string>
#include "ros/ros.h"
#include <sensor_msgs/JointState.h>
#define JOINT_AXE_FRONT_LEFT 0
#define JOINT_AXE_FRONT_RIGHT 1
#define JOINT_AXE_BACK_RIGHT 2
#define JOINT_AXE_BACK_LEFT 3
#define JOINT_WHEEL_FRONT_LEFT 4
#define JOINT_WHEEL_FRONT_RIGHT 5
#define JOINT_WHEEL_BACK_RIGHT 6
#define JOINT_WHEEL_BACK_LEFT 7
#define JOINT_LIDAR 8
#define WHEEL_RADIUS 0.08
// with huge yellow wheel, radius = 0.085 m

double axe_front_left = 0, axe_front_right = 0, axe_back_right = 0, axe_back_left = 0, wheel_front_left = 0, wheel_front_right = 0, wheel_back_right = 0, wheel_back_left = 0, LIDAR;

// AFL = axe_front_left, ABL = axe_back_left, WFL = wheel_front_left, etc.
double AFL_memory = 0, AFR_memory = 0, ABR_memory = 0, ABL_memory = 0, WFL_memory = 0, WFR_memory = 0, WBR_memory = 0, WBL_memory = 0, LIDAR_memory;

void callback(const sensor_msgs::JointState & msg){
	AFL_memory = axe_front_left;
	AFR_memory = axe_front_right;
	ABR_memory = axe_back_right;
	ABL_memory = axe_back_left;
	WFL_memory = wheel_front_left;
	WFR_memory = wheel_front_right;
	WBR_memory = wheel_back_right;
	WBL_memory = wheel_back_left;
	LIDAR_memory = LIDAR;

	axe_front_left=msg.position[JOINT_AXE_FRONT_LEFT];
	axe_front_right=msg.position[JOINT_AXE_FRONT_RIGHT];
	axe_back_right=msg.position[JOINT_AXE_BACK_RIGHT];
	axe_back_left=msg.position[JOINT_AXE_BACK_LEFT];
	wheel_front_left=msg.position[JOINT_WHEEL_FRONT_LEFT];
	wheel_front_right=msg.position[JOINT_WHEEL_FRONT_RIGHT];
	wheel_back_right=msg.position[JOINT_WHEEL_BACK_RIGHT];
	wheel_back_left=msg.position[JOINT_WHEEL_BACK_LEFT];
	LIDAR=msg.position[JOINT_LIDAR];
} 

/**
 * use the angle of a wheel to calcule the distance 
 * distance = circumference * number of rotation, circumference = M_PI * DIAMETER
 */
double distance_calculate(const double previousAngle, const double currentAngle){
	return (M_PI*2*WHEEL_RADIUS)*((currentAngle-previousAngle)/(2*M_PI));
}

/**
 * use a distance to calculate the rotation of the wheel needed
 * the angle is in rad. 
 */
double angle_calculate(const double distance){
	return (distance/(M_PI*2*WHEEL_RADIUS))*(2*M_PI);
}

int main(int argc, char **argv){
  ros::init(argc, argv, "state_listener");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("joint_states", 100, callback);

  /**
   * ros::spin() will enter a loop, pumping callbacks.  With this version, all
   * callbacks will be called from within this thread (the main one).  ros::spin()
   * will exit when Ctrl-C is pressed, or the node is shutdown by the master.
   */
  ros::spin();

  return 0;
}


