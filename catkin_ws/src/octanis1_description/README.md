# Octanis1 description


This package contains the file .urdf (in the folder urdf), which is the representation of the rover in a XML format. If you want to visualize the model, execute the following command-line :
urdf\_to\_graphiz urdf/octanis1.urdf

The file xacro is useful to create the file urdf. It contains many parameters, and we have to use the following command-line to create the file urdf thanks to the file xacro (write the name of the destination instead of 'dest': 
rosrun xacro xacro octanis1.xacro > dest.urdf 

You can create the graph which representes every links of the definition .urdf of the rover.


This package also contains launch files for different operating modes of the rover. These launchfiles depend on external packages.
