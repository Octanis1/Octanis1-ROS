
#define MAVLINK_DIALECT common

#include <ros/ros.h>

#include <sensor_msgs/Imu.h>
#include <bullet/LinearMath/btMatrix3x3.h>
#include <bullet/LinearMath/btQuaternion.h>

#include <mavros_msgs/mavlink_convert.h>


btScalar roll, pitch, yaw;
ros::Time stamp;



void transformquaternion(const sensor_msgs::Imu::ConstPtr &msg){

	 //ROS_INFO("quaternion: [q]", msg->());

	btScalar orient_x;
	btScalar orient_y;
	btScalar orient_z;
	btScalar orient_w;

    stamp = msg->header.stamp;

	
	orient_x=msg->orientation.x;
	orient_y=msg->orientation.y;
	orient_z=msg->orientation.z;
	orient_w=msg->orientation.w;

	btQuaternion q(orient_x, orient_y, orient_z, orient_w);
	btMatrix3x3 m(q);
	
	m.getEulerYPR(yaw, pitch, roll);
	
}



int main(int argc, char **argv){

	//Suscriber part
	ros::init(argc, argv, "attitude_mainboard");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("imu/data", 2000, transformquaternion);



    //Publisher part

    ros::Publisher attitude_pub = n.advertise<mavros_msgs::Mavlink>("mavlink/to", 2000);
    ros::Rate loop_rate(10);


	int count = 0;
	while (ros::ok()) {
	

		//message generation
		//1. make ATTITUDE with type mavlink_message_t
		mavlink_message_t msg;


        mavlink_msg_attitude_pack(13, 21, &msg, stamp.toNSec()/1000, roll, pitch, yaw, 0, 0, 0);

		//2. convert mavlink_message_t to mavros_msgs/Mavlink
		/* inline bool convert(const mavlink_message_t &mmsg, mavros_msgs::Mavlink &rmsg, uint8_t framing_status = mavros_msgs::Mavlink::FRAMING_OK)*/

		auto rmsg = boost::make_shared<mavros_msgs::Mavlink>();

        rmsg->header.stamp = ros::Time::now();
        mavros_msgs::mavlink::convert(msg, *rmsg);





		attitude_pub.publish(rmsg);
		ros::spinOnce();

		loop_rate.sleep();
	 	++count;

	}

	return 0;

}


