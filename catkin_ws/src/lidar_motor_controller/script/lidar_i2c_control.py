#!/usr/bin/env python

import os
import rospy
import time

from std_msgs.msg import Float64, UInt16
from pyA20 import i2c

from mavros.utils import *

#Initialize module to use /dev/i2c-2
i2c.init("/dev/i2c-2")

def set_lidar_motor(speed, direction):
    i2c.open(0x0f) #The slave device address is 0x0f
    #set speed and direction
    i2c.write([0x82, speed, speed]) #speed register, speed a, speed b

    i=0
    while(i<1000):
      i += 1

    print(speed)
    i2c.write([0xaa, direction, 0x01]) #direction register, direction, pa$
    i2c.close() #End communication with slave device


def ramp_up():
   i=10
   while(i<100):
       i += 10
       set_lidar_motor(i,0b1010)
       time.sleep(0.1)


def motor_input_callback(v):
    v_int = v.data
    set_lidar_motor(v_int, 0b1010)


def i2c_listener():
   rospy.init_node('i2c_listener', anonymous=True)
   rospy.Subscriber('motor_input', UInt16, motor_input_callback, queue_size=1)


if __name__ == '__main__':

   print("ramping up motor")
   ramp_up() #starts motor

   i2c_listener()

   rospy.spin()
