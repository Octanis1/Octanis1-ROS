This README explains how to use the package "point_cloud_converter" in order to convert the PointCloud of the Lidar in PointCloud2. 


OVERVIEW

The package "point_cloud_converter" allows to convert the filtered and assembled PointCloud datas in PointCloud2 datas.


DETAILS

The assembled PointCloud obtained with the pakage "lidar" needs then to be converted in a PointCloud2, a more convenient format. The conversion is performed by a c++ file, "converter.cpp", which is in the package "point_cloud_converter". The PointCloud published in the topic "/assembled_cloud" are transformed in PointCloud2 that are then published in the topic "/points2_out". More information about the package can be found on: http://wiki.ros.org/point_cloud_converter
The command is:
rosrun point_cloud_converter converter points2_in:=/my_input_pointcloud2_topic points_out:=/my_output_pointcloud_topic


For the visualization, see the README.txt file of the package "lidar". 
