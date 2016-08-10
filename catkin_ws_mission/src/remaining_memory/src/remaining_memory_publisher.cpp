// This code is inspired from the source code "attitude_mainboard_publisher.cpp"

#define MAVLINK_DIALECT common

#include <ros/ros.h>

#include <sensor_msgs/Imu.h>
#include <bullet/LinearMath/btMatrix3x3.h>
#include <bullet/LinearMath/btQuaternion.h>

#include <mavros_msgs/mavlink_convert.h>
#include<stdio.h>
#include<string.h>


ros::Time stamp;


int main(int argc, char **argv){

    ros::init(argc, argv, "remaining_memory");
	 ros::NodeHandle n;

    //Publisher part

    ros::Publisher remaining_memory_pub = n.advertise<mavros_msgs::Mavlink>("mavlink/to", 2000);
    ros::Rate loop_rate(10);
    
    FILE *in;
	 char buff[512];
    float remaining_memory = 0.0;

    int count = 0;
    while (ros::ok()) {

       // get the remaining memory thanks to a shell script

	    if(!(in = popen("df -h /home/ | xargs | cut -d ' ' -f 14 | sed 's/%//g'", "r"))){
		     exit(1);
	    }

	    while(fgets(buff, sizeof(buff), in)!=NULL){
		     remaining_memory = (float) atoll(buff);
	    }
	    pclose(in);


        //message generation
        //1. make named value float with type mavlink_message_t
        mavlink_message_t msg;
        mavlink_msg_named_value_float_pack(13, 21, &msg, stamp.toNSec()/1000, "remaining_memory", remaining_memory);

        //2. convert mavlink_message_t to mavros_msgs/Mavlink
        /* inline bool convert(const mavlink_message_t &mmsg, mavros_msgs::Mavlink &rmsg, uint8_t framing_status = mavros_msgs::Mavlink::FRAMING_OK)*/

        auto rmsg = boost::make_shared<mavros_msgs::Mavlink>();

        rmsg->header.stamp = ros::Time::now();
        mavros_msgs::mavlink::convert(msg, *rmsg);

		  remaining_memory_pub.publish(rmsg);
		  ros::spinOnce();

		  loop_rate.sleep();
	 	  ++count;
	 }

    return 0;

}


