This README explains how to use the two packages "lidar" and "point_cloud_converter" in order to convert the laserscan of the Lidar in PointCloud2. 


OVERVIEW 

The package "lidar" allows to filter the laserscan datas, and then to transform it in PointCloud and then to assemble all the PointCloud published. 
The package "point_cloud_converter" allows to convert the filtered and assembled PointCloud datas in PointCloud2 datas.


DETAILS

In the lidar package, a script can be found that runs an example of how to use these packages. If the script does not work, type the differents commands of the script manually on your terminal.
These script, "script-run2.sh", starts to play a bag file with a simulation of the LIDAR that will provide the laser data.
Then, the script starts a launch file, "lidar.launch", that filters the laser scans published by the LIDAR by removing useless points. The launch file starts a node of the "laser filters" package and applies different filters to the laser scans. The filters applied can be found on the file "shadow_filter.yaml". More informations about the filters and about the launch file can be found on: http://wiki.ros.org/laser_filters/Tutorials/Laser%20filtering%20using%20the%20filter%20nodes 
After the filtration, the script runs a c++ file, "point2cloud.cpp", that allows to convert the laser scans filtered in PointCloud. In order to convert, different functions of the package "laser_geometry" are used. The PointCloud that are published can be visualized with rviz on the topic "/cloud". More informations about the conversion can be found on: http://wiki.ros.org/laser_pipeline/Tutorials/IntroductionToWorkingWithLaserScannerData
The laser scans converted in PointCloud datas, the latter ones need to be assembled in a composite point cloud. The launch file "pointCloudAssembler.launch" is run by the script. This file starts the node "point_cloud_assembler" from the package "laser_assembler". The point_clou_assembler accumulates the pointCloud published in the topic "/cloud" in a buffer of size 40000 (this parameter can be changed in the launch file). In order to assemble all the accumulated point cloud, the c++ file "periodic_snapshotter.cpp" calls the assemble_scans service with a begin time and an end time. All the PointCloud assembled between this two times are grouped and published in the topic "/assembled_cloud" every 5 seconds. More information on the assemblage can be found on: http://wiki.ros.org/laser_assembler/Tutorials/HowToAssembleLaserScans
The assembled PointCloud obtained need then to be converted in a PointCloud2, a more convenient format. The conversion is performed by a c++ file, "converter.cpp", which is in the package "point_cloud_converter". The PointCloud filtered published in the topic "/assembled_cloud" are transformed in PointCloud2 that are then published in the topic "/points2_out". More information about the package can be found on: http://wiki.ros.org/point_cloud_converter


VISUALIZATION

The different steps of the "lidar" and the "point_cloud_converter" packages can be visualized and checked with rviz.
After running the different commands presented previously, add the following in rviz: 
- a LaserScan that visualizes the topic "scan_filtered"
- a PointCloud that visualizes the topic "/cloud" 
- a PointCloud that visualizes the topic "/assembled_cloud" 
- a PointCloud2 that visualizes the topic "points2_out"
The first topic "/scan_filtered" publishes the filtered laser scans 
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
