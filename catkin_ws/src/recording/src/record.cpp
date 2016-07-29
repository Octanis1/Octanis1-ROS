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

float arm;
ros::Publisher record_pub;

void mavlinkpublish()
{
                mavlink_message_t msg;

        mavlink_msg_command_ack_pack(13, 250, &msg, 400, 0);

                auto rmsg = boost::make_shared<mavros_msgs::Mavlink>();

        rmsg->header.stamp = ros::Time::now();
        mavros_msgs::mavlink::convert(msg, *rmsg);
                record_pub.publish(rmsg);
}

void mavlinkCallback(const mavros_msgs::Mavlink::ConstPtr &msg)
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
	  arm=cmd.param1;
	  mavlinkpublish();
	  if(arm=1){
	    system("roslaunch recording bag.launch");
	    }
	  }
	}
if(arm=0){
	mavlink_message_t message;
	mavlink_status_t status;
	uint8_t i;
	i=0;
	if (msg->msgid==46){
	  while(i<msg->len){
	    uint8_t cp;
            cp=msg->payload64[i];
	    mavlink_parse_char(MAVLINK_COMM_1, cp, &message, &status);
	    i++;
	    }
	  mavlink_mission_item_reached_t mir;
	  mavlink_msg_mission_item_reached_decode(&message, &mir);
	  printf("hi: %u \n", mir.seq);
	  if(mir.seq==0){
  	    system("rosnode kill rosbag");
 	    }
	  }
	}
}
/*
It needs to confirm this message by sending a COMMAND_ACK ( #77 ) message back to the mainboard (via mav_UART) to confirm or deny the command
*/
int main(int argc, char **argv){
	arm=0;
	ros::init(argc, argv, "rover");
	ros::NodeHandle n;
	ros::Publisher record_pub = n.advertise<mavros_msgs::Mavlink>("mavlink/to", 2000);

	ros::Subscriber sub = n.subscribe("mavlink/from", 2000, mavlinkCallback);
	ros::spin();
}

