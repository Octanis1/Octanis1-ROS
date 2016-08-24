#define MAVLINK_DIALECT common
#include <ros/ros.h>
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include <tf2/LinearMath/Quaternion.h>
#include <angles/angles.h>
#include <mavros_msgs/mavlink_convert.h>
#include <tf/tf.h>

float cog = 0.0;
ros::Time stamp;

void mavlinkCallback(const mavros_msgs::Mavlink::ConstPtr &msg)
{
   if(msg->msgid==24)
   {
      mavlink::mavlink_message_t msgarm;
		mavros_msgs::mavlink::convert(*msg, msgarm);

		mavlink::MsgMap map(msgarm);

		mavlink::common::msg::GPS_RAW_INT gri;
		gri.deserialize(map);

      cog = gri.cog;
      if(cog > 3600){ // cog = degree * 100, so if > 3600 there is a problem
         cog = 0.0;
      }
   }
}


int main(int argc, char **argv){

	//Suscriber part
	ros::init(argc, argv, "gps_cog");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("mavlink/from", 500, mavlinkCallback);

   //Publisher part

   ros::Publisher pub = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("gps/cog", 1000);
   ros::Rate loop_rate(10);
   float x_orientation = 0.0;
   float y_orientation = 0.0;
   float z_orientation = 0.0;
   float w_orientation = 0.0;
   float roll = 0;
   float pitch = 0;
   float yaw = angles::from_degrees(cog/100);

   geometry_msgs::Quaternion q = tf::createQuaternionMsgFromRollPitchYaw(roll, pitch, yaw);
   x_orientation = q.x;
   y_orientation = q.y;               
   z_orientation = q.z;
   w_orientation = q.w;

   geometry_msgs::PoseWithCovarianceStamped pose_msg;
	while(ros::ok()) {
		pose_msg.pose.pose.position.x = 0;
      pose_msg.pose.pose.position.y = 0;
      pose_msg.pose.pose.position.z = 0;
      pose_msg.pose.pose.orientation.x = x_orientation;
      pose_msg.pose.pose.orientation.y = y_orientation;
      pose_msg.pose.pose.orientation.z = z_orientation;
      pose_msg.pose.pose.orientation.w = w_orientation;
		pub.publish(pose_msg);	
		ros::spinOnce();
		loop_rate.sleep();
   }

	return 0;

}



