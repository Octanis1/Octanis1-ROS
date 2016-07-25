import os
import sys
import rospy
from time import sleep
from pyA20.gpio import gpio
from pyA20.gpio import port

def shutdowner():
  rospy.init_node('shutdown_node')
  rate = rospy.Rate(10) # 10hz

  if not os.getegid() == 0:
    sys.exit('Script must be run as root')
 
  delay=5

  portToListen = port.PE5
  portToWrite = port.PE4

  gpio.init()
  gpio.setcfg(portToListen, gpio.INPUT)
  gpio.setcfg(portToWrite, gpio.OUTPUT)

  while not rospy.is_shutdown():
    try:
      print ("Press CTRL+C to exit")
      while True:
        v=gpio.input(portToListen)
        if(v==1):
            sleep(2)
            v=gpio.input(portToListen)
            if(v==1):
              print("shutdown of the Olimex")
              gpio.output(portToWrite, 1)
              os.system("sudo halt -p")
              break
        sleep(delay)
    except KeyboardInterrupt:
      print ("Goodbye.")

if __name__ == '__main__':
  try:
    shutdowner()
  except rospy.ROSInterruptException:
    pass
