#include <string>
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
/*#include <tf/transform_broadcaster.h>*/

int main(int argc, char** argv) {
    ros::init(argc, argv, "state_publisher");
    ros::NodeHandle n;
    ros::Publisher joint_pub = n.advertise<sensor_msgs::JointState>("joint_states", 100);
    /*tf::TransformBroadcaster broadcaster;*/
    ros::Rate loop_rate(30);

    const double degree = M_PI/180;

    // robot state
    double axe_front_left = 0, axe_front_right = 0, axe_back_right = 0, axe_back_left = 0, wheel_front_left = 0, wheel_front_right = 0, wheel_back_right = 0, wheel_back_left = 0, LIDAR = 0;

    // message declarations (j'ai desactive l'odometrie pour le moment)
    sensor_msgs::JointState joint_state;
   
	/* geometry_msgs::TransformStamped odom_trans;
	odom_trans.header.frame_id = "odom";
    odom_trans.child_frame_id = "axis";*/

    while (ros::ok()) {
        //update joint_state
        joint_state.header.stamp = ros::Time::now();
        joint_state.name.resize(9);
        joint_state.position.resize(9);
        joint_state.name[0] ="joint_axe_front_left";
        joint_state.position[0] = axe_front_left;
        joint_state.name[1] ="joint_axe_front_right";
        joint_state.position[1] = axe_front_right;
        joint_state.name[2] ="joint_axe_back_left";
        joint_state.position[2] = axe_back_right;
        joint_state.name[3] ="joint_axe_back_right";
        joint_state.position[3] = axe_back_left;
		joint_state.name[4] ="joint_wheel_front_left";
        joint_state.position[4] = wheel_front_left;
        joint_state.name[5] ="joint_wheel_front_right";
        joint_state.position[5] = wheel_front_right;
        joint_state.name[6] ="joint_wheel_back_left";
        joint_state.position[6] = wheel_back_right;
        joint_state.name[7] ="joint_wheel_back_right";
        joint_state.position[7] = wheel_back_left;
		joint_state.name[8] ="joint_LIDAR";
		joint_state.position[8] = LIDAR;

        //send the joint state 
        joint_pub.publish(joint_state);

		// update transform
        // (moving in a circle with radius=2)
        /*odom_trans.header.stamp = ros::Time::now();
        odom_trans.transform.translation.x = cos(angle)*2;
        odom_trans.transform.translation.y = sin(angle)*2;
        odom_trans.transform.translation.z = .7;
        odom_trans.transform.rotation = tf::createQuaternionMsgFromYaw(angle+M_PI/2);

		// send the transform
		broadcaster.sendTransform(odom_trans);			
		*/

        // This will adjust as needed per itercation
        loop_rate.sleep();
    }


    return 0;
}
