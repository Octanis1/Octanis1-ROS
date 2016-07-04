# rover-ros
ROS setup for Octanis Rover SBC.
*octanis1_description* describes the kinematic model and main launch files for the Octanis 1 rover.

*bosch_imu_driver* communicates with IMU over UART and and publishes to /imu/...

*xv_11_laser_driver* communicates with the LIDAR over UART and publishes /scan and /rpms

*urdf\_modelisation\_octanis* is a folder where you can find the modelisation of the Rover. You can realize a modelisation with Rviz by using the .urdf (or the .xacro). You can find the files of the state\_publisher and of the state\_subsciber (we haven't done no tests with these two files, but we will use them soon).

*catkin\_ws* is a folder which contains everything needed to create the representation .urdf of the rover and the graph which corresponds (a graph representing every links of the representation).



