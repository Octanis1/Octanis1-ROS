#include <iostream>

#define MAVLINK_DIALECT common

#include <ros/ros.h>
#include <mavros_msgs/mavlink_convert.h>
#include <stdlib.h>

float arm;
float launch;
ros::Publisher record_pub;

void mavlinkpublish()
{
	mavlink::mavlink_message_t msg;

	mavlink::MsgMap map(msg);

	mavlink::common::msg::COMMAND_ACK ack;
	ack.command = 400;
	ack.result = 0;

	ack.serialize(map);
	
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
		mavlink::mavlink_message_t msgarm;
		mavros_msgs::mavlink::convert(*msg, msgarm);

		mavlink::MsgMap map(msgarm);

		mavlink::common::msg::COMMAND_LONG cmd;
		cmd.deserialize(map);


		if(cmd.command==400)
		{
			arm=cmd.param1;

			mavlinkpublish();

			if(arm==1 && launch==0)
			{
				system("roslaunch recording bag.launch");
				launch=1;
			}
			else if (arm==0 && launch==1)
			{
				system("rosnode kill rosbag");
				launch=0;
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

	if(!record_pub)
	{
		ROS_WARN("publisher invalid");
	}

	ros::Subscriber sub = n.subscribe("from", 2000, mavlinkCallback);

	ros::spin();
}

