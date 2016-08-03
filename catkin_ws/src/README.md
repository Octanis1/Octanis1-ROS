## Packages of the Workspace

# Octanis1\_description

This Package was used to created the file .urdf, i.e the representation of the rover in a XML format. 

# modelisation\_rviz

This package was used to visualize the modelisation of the file .urdf thanks to Rviz.

# lidar

This package can be used to filter the laser scans datas of the LIDAR and then to transform them in point cloud files (PointCloud). Precise informations on how to use the package can be found on the README file in the package. 

# lidar_motor_controller

This package is used to drive lidar's motor via i2c

# point\_cloud\_converter

This package can be used to transform the PointCloud of the LIDAR in PointCloud2. Precise informations on how to use the package can be found on the README file of the package "lidar". 

# octomap_server

This package can be used to transform the PointCloud2 datas obtained from the LIDAR in a 3D OctoMap grid. 

# octovis

This package can be used to visualize the OctoMap datas. 

# pid_lidar

This package uses a closed loop PID to control the speed of the lidar (which should be constant).
