#include <iostream>
#define MAVLINK_DIALECT common
#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <bullet/LinearMath/btMatrix3x3.h>
#include <bullet/LinearMath/btQuaternion.h>
#include <mavros_msgs/mavlink_convert.h>
#include <std_msgs/String.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>

float arm;
float launch;
ros::Publisher record_pub;

void mavlinkpublish()
{
        mavlink_message_t msg;

        mavlink_msg_command_ack_pack(13, 250, &msg, 400, 0);

        auto rmsg = boost::make_shared<mavros_msgs::Mavlink>();

        rmsg->header.stamp = ros::Time::now();
        mavros_msgs::mavlink::convert(msg, *rmsg);

        record_pub.publish(rmsg);

        std::cout<<"published mavmsg id "<<rmsg->msgid<<std::endl;
}

void mavlinkCallback(const mavros_msgs::Mavlink::ConstPtr &msg)
{
if(msg->msgid==76)
{	
        mavlink_message_t msgarm;
        mavros_msgs::mavlink::convert(*msg, msgarm);
        mavlink_command_long_t cmd;
        mavlink_msg_command_long_decode(&msgarm, &cmd);

	if(cmd.command==400)
	{
	  arm=cmd.param1;
	  mavlinkpublish();
	  if(arm==1)
	  {
	    if (launch==0)
	    {
	    system("roslaunch recording bag.launch");
	    launch=1;
	    }
	  }
	  else if (arm==0)
	  {
	    if (launch==1)
	    {
	    system("rosnode kill rosbag");
	    launch=0;
	    }
	  }
	}

}
}
/*
It needs to confirm this message by sending a COMMAND_ACK ( #77 ) message back to the mainboard (via mav_UART) to confirm or deny the command
*/
int main(int argc, char **argv){
	launch=0;
	arm=0;
	ros::init(argc, argv, "rover");
	ros::NodeHandle n("mavlink");
	record_pub = n.advertise<mavros_msgs::Mavlink>("to", 2000);

	if(!record_pub){ROS_WARN("publisher invalid");}
	ros::Subscriber sub = n.subscribe("from", 2000, mavlinkCallback);
	ros::spin();
}

