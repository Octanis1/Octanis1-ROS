This README explains how to use the package "lidar" in order to convert the laserscan of the Lidar in PointCloud, 


OVERVIEW 

The package "lidar" allows to filter the laserscan datas, and then to transform it in PointCloud and then to assemble all the PointCloud published. 


DETAILS
 
In order to transform the laser scans, a file, "point2cloud.cpp", can be found on the src folder. It that allows to convert the laser scans filtered in PointCloud.
The command is :
rosrun lidar point2cloud
In order to convert, different functions of the package "laser_geometry" are used. The PointCloud that are published can be visualized with rviz on the topic "/cloud". More informations about the conversion can be found on: http://wiki.ros.org/laser_pipeline/Tutorials/IntroductionToWorkingWithLaserScannerData

The laser scans converted in PointCloud datas, the latter ones need to be assembled in a composite point cloud with the launch file "pointCloudAssembler.launch". This file starts the node "point_cloud_assembler" from the package "laser_assembler". The point_clou_assembler accumulates the pointCloud published in the topic "/cloud" in a buffer of size 40000 (this parameter can be changed in the launch file). In order to assemble all the accumulated point cloud, the c++ file "periodic_snapshotter.cpp" calls the assemble_scans service with a begin time and an end time. All the PointCloud assembled between this two times are grouped and published in the topic "/assembled_cloud" every 5 seconds. More information on the assemblage can be found on: http://wiki.ros.org/laser_assembler/Tutorials/HowToAssembleLaserScans
The commands to start the launch file and the periodic snapshotter are : 
roslaunch lidar pointCloudAssembler.launch
rosrun lidar periodic_snapshotter


In the lidar package, you can found a launch file, "lidar.launch" that allows to filter the laser scans published by the LIDAR by removing useless points. The launch file starts a node of the "laser filters" package and applies different filters to the laser scans. The filters applied can be found on the file "shadow_filter.yaml" (which is can be found on the package lidar). More informations about the filters and about the launch file can be found on: http://wiki.ros.org/laser_filters/Tutorials/Laser%20filtering%20using%20the%20filter%20nodes 
In order to filter, a modification has to be done. Change the c++ file "point2cloud.cpp" in the src file : on line 21, change the name of the topic "/scan" by "scan_filtered". 



VISUALIZATION

The different steps of the "lidar" and the "point_cloud_converter" packages can be visualized and checked with rviz.
After running the different commands presented previously, add the following in rviz: 
- a LaserScan that visualizes the topic "/scan_filtered" (if you filter the laserscans, otherwise the topic "/scan_filtered should not exist)
- a PointCloud that visualizes the topic "/cloud" 
- a PointCloud that visualizes the topic "/assembled_cloud" 
- a PointCloud2 that visualizes the topic "/points2_out"
The first topic "/scan_filtered" publishes the filtered laser scans if you have decided to filter the laser scans. 
The second topic "/cloud" publishes the filtered PointCloud transformed from the laser scans. 
The third topic "/assembled_cloud" publishes the assembled and filtered PointCloud datas every 5 sec. 
The fourth topic "/points2_out" publishes the assembled, filtered and converted PointCloud2 datas every 5 sec. 


BE CAREFUL

/!\ Some packages might need to be installed so that the "lidar" and the "point_cloud_converter" packages work proprerly. /!\
Here is a non exhaustive list of the packages that might be needed: 
 - laser_geometry
 - laser_assembler
 - laser_pipeline
 - laser_filters
