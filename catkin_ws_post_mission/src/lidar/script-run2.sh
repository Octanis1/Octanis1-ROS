#!/bin/bash

cd ..
cd .. 
xterm -hold -e "rosbag play --clock LIDAR_IMU_TF_MAVLINK_OLIMEX_2016-07-04-21-55-39.bag"& 

xterm -hold -e "source ./devel/setup.bash ; rosrun lidar point2cloud"&

xterm -hold -e "source ./devel/setup.bash; roslaunch lidar pointCloudAssembler.launch"&

xterm -hold -e "source ./devel/setup.bash; rosrun lidar periodic_snapshotter"&

xterm -hold -e "source ./devel/setup.bash; rosrun point_cloud_converter converter points2_in:=/my_input_pointcloud2_topic points_out:=/my_output_pointcloud_topic" &

xterm -hold -e "source ./devel/setup.bash; roslaunch octomap_server octomap_mapping.launch"

exit 0
