# Lidar Motor controller

This package drives the lidar motor via i2c. 

rpms2volts.py converts rpms control effort given by pid node into "volts" (duty cycle of pwm). This convertion is set to be linear i.e  SLOPE*rpms + OFFSET with SLOPE and OFFSET parameters that can be set.

lidar\_i2c\_control.py sends the duty cycle value to the driver via i2c. It starts the motor with a ramp up going from RAMP\_MIN to RAMP\_MAX that can be set.

Launch file init\_lidar\_rotation.launch launches both nodes.
