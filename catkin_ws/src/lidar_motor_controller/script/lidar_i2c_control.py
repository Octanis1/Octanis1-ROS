#!/usr/bin/env python

import rospy
import time
from std_msgs.msg import Float64, UInt16, Bool
from pyA20 import i2c


# REGISTERS AND ADRESSES
REG_speed  = 0x82  # speed register
REG_frqpwm = 0x84  # frequency of pwm register
ADR_slave  = 0x0f  # slave device address

#Initialize module to use /dev/i2c-2
i2c.init("/dev/i2c-2")


def get_params():
    global ramp_min 
    global ramp_max
    global freq_pwm
    
    # Get parameters from launch file
    ramp_min = rospy.get_param('~ramp_min') if rospy.has_param('~ramp_min') else 10
    ramp_max = rospy.get_param('~ramp_max') if rospy.has_param('~ramp_max') else 100
    freq_pwm = rospy.get_param('~frequency_pwm') if rospy.has_param('~frequency_pwm') else 0


def print_params():
   print(" ----- PARAMETERS -----")
   print(" - Ramp min : " + str(ramp_min))
   print(" - Ramp max : " + str(ramp_max))
   print(" - Frequency PWM : " + str(freq_pwm))
   print(" ----------------------")


def set_lidar_motor(speed, direction):
    i2c.open(ADR_slave)  # The slave device address

    # set speed
    i2c.write([REG_speed])  # speed register, 
    i2c.write([speed])  # speed a
    i2c.write([speed])  # speed b

    #i2c.write([0xaa, direction, 0x01]) #direction register, direction, pa$
    i2c.close() #End communication with slave device


def ramp_up(ramp_min, ramp_max):
   print("# INIT : Ramping up motor")
   i = ramp_min
   while(i < ramp_max):
       i += 10
       set_lidar_motor(i,0b1010)
       time.sleep(0.1)

   print("Ramped up to speed %d", ramp_max)


def motor_input_callback(v):
    v_int = v.data
    set_lidar_motor(v_int, 0b1010)
 

def i2c_listener():   
   rospy.Subscriber('motor_input', UInt16, motor_input_callback, queue_size=1)
   rospy.spin()
   

def setFrequencyPWM(freq):
   i2c.open(ADR_slave)
   i2c.write([REG_frqpwm])
   i2c.write([freq])
   i2c.write([freq])
   i2c.close()


if __name__ == '__main__':
   rospy.init_node('lidar_i2c_node', anonymous=True)
   get_params()
   
   # Init
   print_params()
   setFrequencyPWM(freq_pwm)  # Set frequency pwm
   ramp_up(ramp_min,ramp_max)  # Starts motor
   
   # Loop	
   i2c_listener()
   
