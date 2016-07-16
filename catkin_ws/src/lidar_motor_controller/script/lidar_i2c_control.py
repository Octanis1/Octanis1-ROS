#!/usr/bin/env python

import os
import rospy
from std_msgs.msg import Float64, UInt16
from pyA20 import i2c

from mavros.utils import *

def float_to_hex(f):
    return hex(struct.unpack('<I', struct.pack('<f', f))[0])


def motor_input_callback(v):
    #  >>>>>>>>>>>>>>> Change device
    i2c.init("/dev/i2c-2")  # Initialize module to use /dev/i2c-2
    i2c.open(0x0f)  # The slave device address is 0x0f

    # If we want to write to some register
    # >>> Change register	
    # Convert float 64 to hexa 
    v_hex = float_to_hex(v.data)	
    i2c.write([0xAA, v_hex])  # Write 0x20 to register 0xAA
    # i2c.write([0xAA, 0x10, 0x11, 0x12])  # Do continuous write with start address 0xAA

    i2c.close()  # End communication with slave device


def i2c_listener():
	rospy.init_node('i2c_listener', anonymous=True)
	rospy.Subscriber('motor_input', Float64, motor_input_callback)

	rospy.spin()

if __name__ == '__main__':
	while(1):
		i2c_listener()

	
