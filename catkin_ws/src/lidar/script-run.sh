#!/bin/bash

cd $HOME/Octanis1-ROS/catkin_ws
xterm -hold -e "rosbag play --clock src/lidar/LIDAR_IMU_TF_MAVLINK_OLIMEX_2016-07-04-21-55-39.bag"&  
xterm -hold -e "source ./devel/setup.bash ; roslaunch lidar lidar.launch"&
sleep 2
xterm -hold -e "source ./devel/setup.bash ; rosrun lidar point2cloud"&
sleep 2
xterm -hold -e "source ./devel/setup.bash; roslaunch lidar pointCloudAssembler.launch"&
sleep 2
xterm -hold -e "source ./devel/setup.bash; rosrun lidar periodic_snapshotter"&
sleep 2
xterm -hold -e "source ./devel/setup.bash; rosrun point_cloud_converter converter points2_in:=/my_input_pointcloud2_topic points_out:=/my_output_pointcloud_topic"
exit 0


