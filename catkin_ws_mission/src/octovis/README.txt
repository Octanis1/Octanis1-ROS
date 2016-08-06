Octomap
- A probabilistic, flexible, and compact 3D mapping library for robotic systems.

Authors: K. M. Wurm, A. Hornung, University of Freiburg, Copyright (C) 2009-2012.
http://octomap.sourceforge.net/

Octovis is a visualization tool and library for OctoMap.
It is distributed under the GPL license (see "LICENSE.txt").

Octivos is based on QGLViewer,distributed under the GPL license (see 
"octovis/src/extern/QGLViewer/LICENSE" and the author's exception 
"octovis/src/extern/QGLViewer/GPL_EXCEPTION")


LINUX
############################

You can build octovis independently of octomap by following
the these steps:

  cd octovis
  mkdir build
  cd build
  cmake ..
  make
  
  
You can manually set the location of the octomap library with the
octomap_DIR variable in CMake.

Note: If you get an error such as

"CMake Error at /usr/share/cmake-2.8/Modules/FindQt4.cmake:1148 (MESSAGE):
  Qt qmake not found!"

but you have Qt4 installed, this probably means that both Qt3 and Qt4
are installed. In Ubuntu this can be resolved using:
$ sudo update-alternatives --config qmake"


WINDOWS
############################

The octomap viewer "octovis" can be compiled and used under
Windows although this has not been tested in-depth. Feedback 
is welcome ("it works" is nice too :-)

To compile the library you need:

 - OpenGL
 - cmake (http://www.cmake.org)
 - QT development environment (see below)


MinGW
------------------------------

* Download the MinGW distribution (http://www.mingw.org)
* Install C++ compiler and add MingGW/bin to your system PATH

* Download the QT library with MinGW support 
  (http://qt.nokia.com/downloads)

* First build the GQLViewer library
   - Open a windows shell (e.g., from the START-Menu -> QT)
   - cd octovis/src/extern/QGLViewer
   - qmake
     (I had to fix a small bug in the Makefile)
   - mingw32-make
   - This will generate QGLViewer2.dll and libQGLViewer2.a

The viewer should be build along with the rest of the octomap package:

* from a shell execute: 
   - cd octomap/build
   - cmake -G "MinGW Makefiles" ..
   - mingw32-make


Microsoft Visual Studio 2010
------------------------------

* Download the QT library with Visual Studio 20xx support (currently 2008)
  (http://qt.nokia.com/downloads)

* To build the qglviewer library
  - open a windows shell (e.g., from the START-Menu -> QT) 
  - cd octovis/src/extern/QGLViewer
  - qmake -t vclib QGLViewer.pro -spec win32-msvc2010
    (ignore any warnings)
  - Load the generated file QGLViewer.vcxproj and build the project.
    This will give you the files QGLViewer2.(dll,lib) that we will need.

The viewer should be build along with the rest of the octomap package.
These steps will create a solution file for the library and the viewer:

* Start the cmake-gui and set the code directory to the octomap main directory.
* Set the build directory to, e.g., /build
* Press "Generate", select the appropriate generator, e. g. "Visual Studio 10".
* This generates a solution file octomap-distribution.sln
  Load this file and build the project.
  
Some more hints on compiling with Visual Studio (these may be necessary depending
on the VS version and CMake version):
* When compiling QGLViewer, modify the output path in "Properties->Linker->
  General->Output". Remove the "debug" and "release" prefix so the libs are 
  installed in the base dir.
* For the octivis-shared target, add the Qt lib path ("C:\path\to\Qt\4.7.2\lib") 
  to "Properties->Linker->General->Additional Library Directories", and add 
  the following Qt libs as dependencies in "Properties->Linker->Input->
  Additional Dependencies": QtCore4.lib, QtOpenGL4.lib, QtGui4.lib and 
  QtXml4.lib (and the debug versions of them to the Debug configuration)
* If the debug version of octovis throws this error: "QWidget: Must construct a 
  QApplication before a QPaintDevice", it is linking to the release version of 
  QGLViewer. Change the library dependency of octovis and octovis-shared to the 
  debug version QGLViewerd2.lib in "Properties->Linker->Input->Additional 
  Dependencies".
  

When executing octovis.exe, Windows needs to find the following 
libraries, so make sure they are on the PATH or in the same 
directory: QGLViewer2.dll, QtOpenGL4.dll, QTGui4.dll, QTCore4.dll


