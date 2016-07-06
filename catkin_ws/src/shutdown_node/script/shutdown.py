#!/usr/bin/env python

import os
import rospy
from sensor_msgs.msg import JointState
from std_msgs.msg import Header
import math
import numpy as np
import mavros
from mavros.utils import *
from mavros_msgs.msg import Mavlink

""" 75 = COMMAND_INT et payload64[0] enables us to recognize the command to shutdown """
def shutdown_olimex(m):
	if(m.msgid == 75 and m.payload64[0] == 4611686018427387904):
		os.system("sudo halt -p")
		#os.system("echo \"Hello World !\"")

def listener():
	rospy.init_node('shutdown_node')
	rospy.Subscriber("/mavlink/from", Mavlink, shutdown_olimex)

	rospy.spin()

if __name__ == '__main__':
	while(1):
		listener()

	
