// This code is inspired from the source code "attitude_mainboard_publisher.cpp"

#define MAVLINK_DIALECT common

#include <ros/ros.h>

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
        mavlink::mavlink_message_t msg;
        mavlink::MsgMap map(msg);

	mavlink::common::msg::NAMED_VALUE_FLOAT mem_msg;

	std::array<char, 10> name = {"rem_mem"};

	mem_msg.time_boot_ms = stamp.toNSec()/1000;
	mem_msg.name = name;
	mem_msg.value = remaining_memory;


	mem_msg.serialize(map);

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


