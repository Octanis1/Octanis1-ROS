#!/usr/bin/env python

import rospy
import time
from std_msgs.msg import Float64, UInt16, Bool
from pyA20 import i2c


# REGISTERS AND ADRESSES
REG_speed  = 0x82  # speed register
ADR_slave  = 0x0f  # slave device address

#Initialize module to use /dev/i2c-2
i2c.init("/dev/i2c-2")


def get_params():
    global ramp_min
    global ramp_max

    # Get parameters from launch file
    ramp_min = rospy.get_param('~ramp_min') if rospy.has_param('~ramp_min') else 10
    ramp_max = rospy.get_param('~ramp_max') if rospy.has_param('~ramp_max') else 100


def print_params():
   print(" ----- PARAMETERS -----")
   print(" - Ramp min : " + str(ramp_min))
   print(" - Ramp max : " + str(ramp_max))
   print(" ----------------------")


def set_lidar_motor(speed, direction):
<<<<<<< HEAD

    i2c.open(0x0f)  # The slave device address is 0x0f

    #set speed
    i2c.write([0x82])  # speed register
    i2c.write([speed])  # speed a
    i2c.write([speed])  # speed b

#    i=0
#    while(i<1000):
#      i += 1

    print(speed)
=======
    i2c.open(ADR_slave)  # The slave device address

    # set speed
    i2c.write([REG_speed])  # speed register, 
    i2c.write([speed])  # speed a
    i2c.write([speed])  # speed b

>>>>>>> 1cfc4ce28e30b56cb7d7959adafc9823e496df20
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

<<<<<<< HEAD

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

=======
>>>>>>> 1cfc4ce28e30b56cb7d7959adafc9823e496df20

def i2c_listener():
   rospy.Subscriber('motor_input', UInt16, motor_input_callback, queue_size=1)
   rospy.spin()

if __name__ == '__main__':
   rospy.init_node('lidar_i2c_node', anonymous=True)
   get_params()

   # Init
   print_params()
   ramp_up(ramp_min,ramp_max)  # Starts motor

<<<<<<< HEAD
   #set frequency pwm
#   i2c.open(0x0f)
   i2c.write([0x84])
   i2c.write([6])
   i2c.write([6])
   ramp_up(10,100) #starts motor
#   i2c.close()

=======
>>>>>>> 1cfc4ce28e30b56cb7d7959adafc9823e496df20
   # Loop
   i2c_listener()
