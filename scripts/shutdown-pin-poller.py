#!/usr/bin/env python

import os
import sys
sys.path.append("/home/rover/.local/lib/python2.7/site-packages")
print sys.path

from time import sleep
from pyA20.gpio import gpio
from pyA20.gpio import port

def shutdowner():

  if not os.getegid() == 0:
    sys.exit('Script must be run as root')

  delay=5

  portToListen = port.PI2 #13
  portToWrite = port.PI1 #11

  gpio.init()
  gpio.setcfg(portToListen, gpio.INPUT)
  gpio.setcfg(portToWrite, gpio.OUTPUT)
  gpio.output(portToWrite, 1) #this tells EPS that shutdown script is running fine

  while 1:
        v=gpio.input(portToListen)
	print v
        if(v==1):
            sleep(delay)
            v=gpio.input(portToListen)
            if(v==1):
              print("shutdown of the Olimex")
	      gpio.output(portToWrite, 1)
              os.system("sudo halt -p")
              break
        sleep(delay)

if __name__ == '__main__':
  try:
    shutdowner()
  except KeyboardInterrupt:
    pass
