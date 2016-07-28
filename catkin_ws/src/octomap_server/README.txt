OVERVIEW

This package can be used to create an OctoMap 3D grid from an assembled point cloud (PointCloud2). The octomap created can then be saved in a file and visualized with the package octovis. 


DETAILS

In order to create the OctoMap 3D grid, you need to have a PointCloud2 with the assembled datas of the laser scans. 
Run the following command in a new terminal (do not forget to source before): 
rosrun octomap_server octomap_mapping.launch
The launch file opened starts to create an OctoMap from the PointCloud2 published in the topic "/points2_out" (you can rename it in the launch file depending on which topic your PointCloud2 is being published) and publishes the OctoMap in the topic "/occupied_cells_vis_array". 
The resolution of the OctoMap can be modified in this launch file. By default, it is set at 0.05 cm. 
The OctoMap published can be visualized in rviz by adding a "MarkerArray" entry targetting the topic "/occupied_cells_vis_array".
Then, it is possible to save the OctoMap in a file by running this command:
rosrun octomap_server octomap_saver name_of_the_file.bt
Replace name_of_the_file by the name of the file where you want to save the OctoMap. The name has to finished by the extension ".bt". 
After the saving, you can visualize the OctoMap with the package octovis. Run the command:
octovis name_of_the_file.bt


BE CARFUL
    
You might need to install these packages to ensure that everything works:
 - octomap
 - octomap_mapping
 - octomap_server
 - octovis       
