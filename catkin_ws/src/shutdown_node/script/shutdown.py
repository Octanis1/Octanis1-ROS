import os
import sys

if not os.getegid() == 0:
    sys.exit('Script must be run as root')


from time import sleep
from pyA20.gpio import gpio
from pyA20.gpio import port

delay=5

portToListen = port.PE5
portToWrite = port.PE4

gpio.init()
gpio.setcfg(portToListen, gpio.INPUT)
gpio.setcfg(portToWrite, gpio.OUTPUT)

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
