This README explains how to use the two packages "lidar" and "point_cloud_converter" in order to convert the laserscan of the Lidar in PointCloud2. 
The package "lidar" allows to filter the laserscan datas, and then to transform it in PointCloud and then to assemble all the PointCloud published. 
The package "point_cloud_converter" allows to convert the filtered and assembled PointCloud datas in PointCloud2 datas.

In order to run the two packages, you have first to open rviz with special configurations. 
In rivz, add : 
- a PointCloud that visualizes the topic "/cloud" 
- a PointCloud that visualizes the topic "/assembled_cloud" 
- a PointCloud2 that visualizes the topic "points2_out"
The first topic "/cloud" publishes the filtered PointCloud transformed from the laserscan datas. 
The second topic "/assembled_cloud" publishes the assembled and filtered PointCloud datas every 5 sec. 
The third topic "/points2_out" publishes the assembled, filtered and converted PointCloud2 datas every 5 sec. 

After the rviz configurations, go in the lidar folder, and run the script "script-run.sh". The PointCloud2 datas assembled and filtered will be published every 5 sec in the topic "points2_out" and can be visualized in rviz.
