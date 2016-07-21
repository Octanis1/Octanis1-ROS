#!/usr/bin/env python

import rospy
import message_filters
from std_msgs.msg import UInt16
from std_msgs.msg import Float64


def convert_to_volts_callback(r):

    new_rpms = float(current_rpms) + r.data
    
    # We receive the information of the control_effort topic that indicates the value in rpms. Convert it into volts
    # We have in normal conditions : 3V -> 190 rpms
    # Volts value should be in pwm duty cycle
    pwm_dc0 = round(0.6*255) # 0.6 ?
    rpm0 = 190
    
    pwm_dc = float(new_rpms)*(pwm_dc0/rpm0)

    # Check that we don't exceed the maximum and minimum voltage
    # >>>>>>>>> Not sure of min value...
    pwm_dc_max = 255
    pwm_dc_min = round(0.4*255) # 120 rpm
    if pwm_dc > pwm_dc_max:
        pwm_dc = pwm_dc_max
    elif pwm_dc < pwm_dc_min:
        pwm_dc = pwm_dc_min

    # >>>>>>>>> CONVERT INTO UINT16 FORMAT

    # Publish to motor_input (will then be transmitted via i2c to motor)
    pub = rospy.Publisher('motor_input', UInt16, queue_size=10)   
    rospy.loginfo(pwm_dc)
    pub.publish(pwm_dc)

    return


def get_rpms_callback(r):
    global current_rpms
    current_rpms = r.data
    print("rpms_callback %d", current_rpms)
    
    return   

#def callback(rpms_info, control_info):
#    print("Hi")


def rpms2volts():
    rospy.init_node('rpms_to_volts', anonymous=True)
    rospy.Subscriber('rpms', UInt16, get_rpms_callback)
    rospy.Subscriber('control_effort', Float64, convert_to_volts_callback)
    
    #rpms_sub = message_filters.Subscriber('rpms', UInt16)
    #control_sub = message_filters.Subscriber('control_effort', Float64)
    #ts = message_filters.TimeSynchronizer([rpms_sub, control_sub], 10)
    #ts.registerCallback(callback)     

    rospy.spin()

    return


if __name__ == '__main__':
    while(1):
	current_rpms = 0
        rpms2volts()
