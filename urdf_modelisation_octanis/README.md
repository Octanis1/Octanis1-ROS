# General Description : 
This folder contains the files which modelise the rover.

to see the static modelisation of the rover, enter the command :
roslaunch urdf_tutorial display.launch model:=urdf/octanis1.urdf 
to see the dynamic modelisation of the rover (in rviz), enter the command :
roslaunch urdf_tutorial display.launch model:=urdf/octanis1.urdf gui:=True

I have written the state-publisher but I have problems to launch it. The tuto I used :
http://wiki.ros.org/urdf/Tutorials/Using%20urdf%20with%20robot\_state\_publisher

# Gazebo
We have to realize a real simulation, with calculs of gravity, etc. So I propose to use Gazebo (it's proposed by the tutorial of ROS). We can do the simulation of everything with Gazebo (links, sensors, etc.).
However it's only a software of simulation. I will do the simulations with Gazebo, but I think we won't use it on the Olimex because I don't think it useful in real time.

