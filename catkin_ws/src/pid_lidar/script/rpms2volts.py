
import rospy
from std_msgs.msg import Float64, UInt16

def convert_to_volts_callback(r):
    # We receive the information of the control_effort topic that indicates the value in rpms. Convert it into volts
    # We have in normal conditions : 3V -> 180 rpms
    # Volts value should be in pwm duty cycle
    pwm_dc0 = 0.6 # 0.6 ?
    rpm0 = 180
    
    pwm_dc = double(r.data)*(pwm_dc0/rpm0)

    # Check that we don't exceed the maximum and minimum voltage
    # >>>>>>>>> Not sure of min value...
    pwm_dc_max = 1.0
    pwm_dc_min = 0.4 # 120 rpm
    if pwm_dc > pwm_dc_max:
        pwm_dc = pwm_dc_max
    elif pwm_dc < pwm_dc_min:
        pwm_dc = pwm_dc_min

    # Publish to motor_input (will then be transmitted via i2c to motor)
    pub = rospy.Publisher('motor_input', Float64, queue_size=10)
    while not rospy.is_shutdown():
        rospy.loginfo(pwm_dc)
        pub.publish(pwm_dc)


def rpms2volts():
    rospy.init_node('rpms_to_volts', anonymous=True)
    rospy.Subscriber('control_effort', UInt16, convert_to_volts_callback)

    rospy.spin()


if __name__ == '__main__':
    while(1):
        rpms2volts()