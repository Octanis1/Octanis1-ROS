#!/usr/bin/env python

import os
import rospy
import time

from std_msgs.msg import Float64, UInt16, Bool
from pyA20 import i2c

from mavros.utils import *

#Initialize module to use /dev/i2c-2
i2c.init("/dev/i2c-2")

#global command_counter = 0

def set_lidar_motor(speed, direction):
    i2c.open(0x0f)  # The slave device address is 0x0f
    #set speed
    i2c.write([0x82]  # speed register, 
    i2c.write([speed])  # speed a
    i2c.write([speed])  # speed b

#    i=0
#    while(i<1000):
#      i += 1

    #print(speed)
    #i2c.write([0xaa, direction, 0x01]) #direction register, direction, pa$
    i2c.close() #End communication with slave device


def ramp_up(ramp_min, ramp_max):

   print("# INIT : Ramping up motor")
   i=ramp_min
   while(i<ramp_max):
       i += 10
       set_lidar_motor(i,0b1010)
       time.sleep(0.1)

   print("Ramped up to speed %d", ramp_max)


def motor_input_callback(v):
    v_int = v.data
    set_lidar_motor(v_int, 0b1010)

    #global command_counter += 1
    #if command_counter < 2000:
	#set_lidar_motor(v_int, 0b1010)
    #else:
	#global command_counter = 0
	#ramp_up(50, 150)	


#def reset_lidar_callback(r):
#    # Desactivate PID
#    pub = rospy.Publisher('pid_enable', Bool, queue_size=10)
#    rospy.loginfo(False)
#    pub.publish(False)
    
#    # Reset
#    ramp_up(50,120)
    
#    # Activate PID
#    pub = rospy.Publisher('pid_enable', Bool, queue_size=10)
#    rospy.loginfo(True)
#    pub.publish(True)
 

def i2c_listener():
   rospy.init_node('i2c_listener', anonymous=True)
   rospy.Subscriber('motor_input', UInt16, motor_input_callback, queue_size=1)
   #rospy.Subscriber('reset_lidar', Bool, reset_lidar_callback)


if __name__ == '__main__':
   # Init

   #set frequency pwm
   i2c.write([0x84])
   i2c.write([6])
   i2c.write([6])
   ramp_up(10,100) #starts motor
   
   # Loop	
   i2c_listener()
   rospy.spin()
