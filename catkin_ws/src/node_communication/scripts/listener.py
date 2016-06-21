#!/usr/bin/env python
import rospy
from sensor_msgs.msg import JointState
from std_msgs.msg import Header
import math

WHEEL_RADIUS = 0.08


""" AFL = axe_front_left, ABL = axe_back_left, WFL = wheel_front_left, etc."""
AFL, AFR, ABR, ABL, WFL, WFR, WBR, WBL, LIDAR = 0,0,0,0,0,0,0,0,0
xRover, yRover, zRover = 0,0,0

def gestion_rotation(list_variables, list_rotations):
	for i in range(len(list_variables)):
		if(int(list_rotations[i]) > 0):
			list_variables[i]-=int(list_rotations[i])*2*math.pi
		elif(int(list_rotations[i]) < 0):
			list_variables+=int(list_rotations[i])*2*math.pi
	return list_variables

""" use the angle of a wheel to calcule the distance.
	distance = circumference * number of rotation, circumference = M_PI * DIAMETER
"""
def distance_calculate(previousAngle, currentAngle):
	return (math.pi*2*WHEEL_RADIUS)*((currentAngle-previousAngle)/(2*math.pi));

""" use a distance to calculate the rotation of the wheel needed
	the angle is in rad. 
"""
def angle_calculate(distance):
	return (distance/(math.pi*2*WHEEL_RADIUS))*(2*math.pi);

def callback(data):
	global AFL, AFR, ABR, ABL, WFL, WFR, WBR, WBL, LIDAR
	global xRover, yRover, zRover
		

	AFL_previous, AFR_previous, ABR_previous, ABL_previous, WFL_previous, WFR_previous, WBR_previous, WBL_previous, LIDAR_previous = AFL, AFR, ABR, ABL, WFL, WFR, WBR, WBL, LIDAR
	AFL, AFR, ABR, ABL, WFL, WFR, WBR, WBL, LIDAR = data.position[0],data.position[1],data.position[2],data.position[3],data.position[4],data.position[5],data.position[6],data.position[7],data.position[8]

	""" gestion_rotation is useful because when a position of a joint become negativ because of a full rotation, we have to change the computation of the distance. In fact, when the position in > PI or < -PI, the publisher change the value. When the publisher change one value, it writes something in data.velocity. The function gestion_rotation changes the variables in the subscriber by modifying the variables AFL_previous, AFR_previous, etc."""
	AFL_previous, AFR_previous, ABR_previous, ABL_previous, WFL_previous, WFR_previous, WBR_previous, WBL_previous, LIDAR_previous = gestion_rotation([AFL_previous, AFR_previous, ABR_previous, ABL_previous, WFL_previous, WFR_previous, WBR_previous, WBL_previous, LIDAR_previous],data.velocity)

	xRover+= distance_calculate(WFL_previous,WFL)
	print("wheel FL : "+str(WFL)+" wheel FL previously : "+str(WFL_previous))
	print("x : "+str(xRover)+"\ny : "+str(yRover)+"\nz :"+str(zRover))
	#rospy.loginfo(data.position)
	#rospy.loginfo(data.velocity)

def listener():
    rospy.init_node('joint_states_subscriber')

    rospy.Subscriber("joint_states", JointState, callback)

    rospy.spin()

if __name__ == '__main__':
    listener()
