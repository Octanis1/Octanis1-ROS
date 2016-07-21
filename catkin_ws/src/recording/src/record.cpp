#include <iostream>
#include <stdlib.h>
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


void mavlinkCallback(const mavros_msgs::Mavlink::ConstPtr& msg)
{
if(msg->msgid==76){	
	mavlink_message_t msgarm;
	mavlink_status_t stsarm;
	uint8_t i;
	i=0;
	while(i<msg->len){
	  uint8_t cp;
	  cp=msg->payload64[i];
	  mavlink_parse_char(MAVLINK_COMM_1, cp, &msgarm, &stsarm);
	  i++;
	  }
 	mavlink_command_long_t cmd;
 	mavlink_msg_command_long_decode(&msgarm, &cmd);
	if(cmd.command==400){
	  if(cmd.param1=1){
	    system("roslaunch recording bag.launch");
	    }
	  else{
	    mavlink_message_t message;
            mavlink_status_t status;
	    uint8_t i;
	    i=0;
	    if (msg->msgid==24){
	      while(i<msg->len){
	        uint8_t cp;
                cp=msg->payload64[i];
	        mavlink_parse_char(MAVLINK_COMM_1, cp, &message, &status);
	        i++;
	        }
	      mavlink_gps_raw_int_t gps;
	      mavlink_msg_gps_raw_int_decode(&message, &gps);
	      printf("hi: %u \n", gps.lat);
	      if(gps.lat==0){
  	        system("rosnode kill rosbag");
 	        }
	      }
	    }
	  }
	}
}

int main(int argc, char **argv){

	
	ros::init(argc, argv, "rover");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("mavlink/from", 2000, mavlinkCallback);
	ros::spin();

}

