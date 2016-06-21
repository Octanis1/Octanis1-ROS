#!/usr/bin/env python
# license removed for brevity
import rospy
from sensor_msgs.msg import JointState
from std_msgs.msg import Header
import math

def check_radian(my_list):
	new_list=[]
	rotations=[]
	for i in my_list:
		nbRotations=0
		while(i>math.pi):
			i-=2*math.pi
			nbRotations+=1
		while(i<-math.pi):
			i+=2*math.pi
			nbRotations-=1
		new_list.append(i)
		rotations.append(nbRotations)
	return new_list+rotations

def talker():
    pub = rospy.Publisher('joint_states', JointState, queue_size=100)
    rospy.init_node('joint_states_publisher')
    rate = rospy.Rate(30) # 10hz
    AFL, AFR, ABR, ABL, WFL, WFR, WBR, WBL, LIDAR = 0,0,0,0,0,0,0,0,0
    rotAFL, rotAFR, rotABR, rotABL, rotWFL, rotWFR, rotWBR, rotWBL, rotLIDAR=0,0,0,0,0,0,0,0,0

    while not rospy.is_shutdown():
		hello_str = JointState()
		hello_str.header = Header()
		hello_str.header.stamp = rospy.Time.now()
		hello_str.name = ['joint_axe_front_left', 'joint_axe_front_right', 'joint_axe_back_left', 'joint_axe_back_right', 'joint_wheel_front_left', 'joint_wheel_front_right', 'joint_wheel_back_left', 'joint_wheel_back_right', 'joint_LIDAR']
		hello_str.position = [AFL, AFR, ABR, ABL, WFL, WFR, WBR, WBL, LIDAR]
		hello_str.velocity = [rotAFL, rotAFR, rotABR, rotABL,rotWFL, rotWFR, rotWBR, rotWBL, rotLIDAR]
		hello_str.effort = []
		pub.publish(hello_str)
		WFL, WFR, WBR, WBL= WFL+0.1, WFR+0.1, WBR+0.1, WBL+0.1
		AFL, AFR, ABR, ABL, WFL, WFR, WBR, WBL, LIDAR, rotAFL, rotAFR, rotABR, rotABL, rotWFL, rotWFR, rotWBR, rotWBL, rotLIDAR=[i for i in check_radian([AFL, AFR, ABR, ABL, WFL, WFR, WBR, WBL, LIDAR])]
		rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
