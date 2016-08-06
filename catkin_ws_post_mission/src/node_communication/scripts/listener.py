#!/usr/bin/env python

""" this listener get the informations of the joints of the rover, and will broadcast the informations about the rover (x,y,z), (angle1,angle2,angle3). It will publisher too the informations about the LIDAR (same canal as (x,y,z),(angle1,angle2,angle3) ?)
"""

import rospy
from sensor_msgs.msg import JointState
from std_msgs.msg import Header
import math
import numpy as np

WHEEL_RADIUS = 0.08


""" AFL = axe_front_left, ABL = axe_back_left, WFL = wheel_front_left, etc."""
AFL, AFR, ABR, ABL, WFL, WFR, WBR, WBL, LIDAR = 0,0,0,0,0,0,0,0,0
xRover, yRover, zRover, yaw, pitch, roll = 0,0,0,0,0,0

def rotation_matrix(yaw, pitch, roll):
	matrix=[[0,0,0],[0,0,0],[0,0,0]]
	matrix[0][0]=math.cos(yaw)*math.cos(pitch)
	matrix[0][1]=math.cos(yaw)*math.sin(pitch)*math.sin(roll)-math.sin(yaw)*math.cos(roll)
	matrix[0][2]=math.cos(yaw)*math.sin(pitch)*math.cos(roll)+math.sin(yaw)*math.sin(roll)
	matrix[1][0]=math.sin(yaw)*math.cos(pitch)
	matrix[1][1]=math.sin(yaw)*math.sin(pitch)*math.sin(roll)+math.cos(yaw)*math.cos(roll)
	matrix[1][2]=math.sin(yaw)*math.sin(pitch)*math.cos(roll)-math.cos(yaw)*math.sin(roll)
	matrix[2][0]=-math.sin(pitch)
	matrix[2][1]=math.cos(pitch)*math.sin(roll)
	matrix[2][2]=math.cos(pitch)*math.cos(roll)
	return matrix

def transpose_3d(matrix):
	matrixT=[[0,0,0],[0,0,0],[0,0,0]]
	for i in range(3):
		for j in range(3):
			matrixT[j][i]=matrix[i][j]
	return matrixT

def matmult(a, b):
	a = np.array(a)
	b = np.array(b)
	return a.dot(b)

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

def distance_rover(WFL_dist, WFR_dist, WBR_dist, WBL_dist, x, y, z, yaw, pitch, roll):
	distance=0
	""" computation of the distance that the center of the rover has traveled. It can be negativ (reverse gear) """
	if(min(abs(WFL_dist),abs(WFR_dist))==abs(WFL_dist)):
		distance = WFL_dist
	else:
		distance = WFR_dist
	""" computation of the new (x,y,z)"""
	rotation_reference=rotation_matrix(yaw,pitch,roll)
	rotation_reference=transpose_3d(rotation_reference)
	[[deltaX],[deltaY],[deltaZ]]=matmult(rotation_reference, [[0], [distance], [0]])
	x,y,z=x+deltaX,y+deltaY,z+deltaZ
	""" computation of the new (yaw, pitch, roll). If we check the wheels, only the yaw can change """
	if(WFL_dist > WFR_dist): # turn left, so we have to decrease yaw 
		yaw-=angle_calculate(WFL_dist - WFR_dist)	
	elif(WFL_dist < WFR_dist): # turn left, so we have to increase yaw
		yaw+=angle_calculate(WFR_dist - WFL_dist)
	return x, y, z, yaw, pitch, roll

def callback(data):
	global AFL, AFR, ABR, ABL, WFL, WFR, WBR, WBL, LIDAR
	global xRover, yRover, zRover, yaw, pitch, roll	

	AFL_previous, AFR_previous, ABR_previous, ABL_previous, WFL_previous, WFR_previous, WBR_previous, WBL_previous, LIDAR_previous = AFL, AFR, ABR, ABL, WFL, WFR, WBR, WBL, LIDAR
	AFL, AFR, ABR, ABL, WFL, WFR, WBR, WBL, LIDAR = data.position[0],data.position[1],data.position[2],data.position[3],data.position[4],data.position[5],data.position[6],data.position[7],data.position[8]

	""" gestion_rotation is useful because when a position of a joint become negativ because of a full rotation, we have to change the computation of the distance. In fact, when the position in > PI or < -PI, the publisher change the value. When the publisher change one value, it writes something in data.velocity. The function gestion_rotation changes the variables in the subscriber by modifying the variables AFL_previous, AFR_previous, etc."""
	AFL_previous, AFR_previous, ABR_previous, ABL_previous, WFL_previous, WFR_previous, WBR_previous, WBL_previous, LIDAR_previous = gestion_rotation([AFL_previous, AFR_previous, ABR_previous, ABL_previous, WFL_previous, WFR_previous, WBR_previous, WBL_previous, LIDAR_previous],data.velocity)

	WFL_dist, WFR_dist, WBR_dist, WBL_dist = distance_calculate(WFL_previous,WFL), distance_calculate(WFR_previous,WFR), distance_calculate(WBR_previous,WBR), distance_calculate(WBL_previous,WBL)
	xRover, yRover, zRover, yaw, pitch, roll = distance_rover(WFL_dist, WFR_dist, WBR_dist, WBL_dist, xRover, yRover, zRover, yaw, pitch, roll)

	print("x : "+str(xRover)+"\ny : "+str(yRover)+"\nz :"+str(zRover))
	print("yaw : "+str(yaw)+"\npitch : "+str(pitch)+"\nroll :"+str(roll))

def listener():
    rospy.init_node('joint_states_subscriber')

    rospy.Subscriber("joint_states", JointState, callback)

    rospy.spin()

if __name__ == '__main__':
    listener()
