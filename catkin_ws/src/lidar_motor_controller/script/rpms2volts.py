#!/usr/bin/env python

import rospy
from std_msgs.msg import UInt16
from std_msgs.msg import Float64

def get_params():
    global slope
    global offset 

    slope  = rospy.get_param('~slope') if rospy.has_param('~slope') else 0.16
    offset = rospy.get_param('~offset') if rospy.has_param('~offset') else 48


def print_params():
   print(" ----- PARAMETERS -----")
   print(" - Slope : " + str(slope))
   print(" - Offset : " + str(offset))
   print(" ----------------------")


def convert_to_volts_callback(r):
    new_rpms = float(current_rpms) + r.data

    # We receive the information of the control_effort topic that indicates the value in rpms. Convert it into "volts" (value of pwm)
    # According to calibration of lidar in normal conditions : VAL_PWM = 0,16*RPMS + 48

    pwm = round( slope*new_rpms + offset )

    # Check that we don't exceed the maximum and minimum voltage
    pwm_max = 255
    pwm_min = 40 
    if pwm > pwm_max:
        pwm = pwm_max
    elif pwm < pwm_min:
        pwm = pwm_min

    # Publish to motor_input (will then be transmitted via i2c to motor)
    pub = rospy.Publisher('motor_input', UInt16, queue_size=10)
    rospy.loginfo(pwm)
    pub.publish(pwm)


def get_rpms_callback(r):
    global current_rpms
    current_rpms = r.data


def rpms2volts():
    rospy.Subscriber('rpms', UInt16, get_rpms_callback)
    rospy.Subscriber('control_effort', Float64, convert_to_volts_callback)
    rospy.spin()


if __name__ == '__main__':
   rospy.init_node('rpms2volts_node', anonymous=True)
   get_params()
   print_params()

   current_rpms = 0
   rpms2volts()
