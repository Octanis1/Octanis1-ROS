1.12.19 (2016-07-24)
--------------------
* Add colormap option in video_recorder
* Merge pull request `#203 <https://github.com/ros-perception/image_pipeline/issues/203>`_ from wkentaro/video-recorder-timestamp
  [image_view] Stamped video output filename for video recorder
* bump version requirement for cv_bridge dep
  Closes `#215 <https://github.com/ros-perception/image_pipeline/issues/215>`_
* Request for saving image with start/end two triggers
* Stamped video output filename
  - _filename:=output.avi _stamped_filename:=false -> output.avi
  - _filename:=_out.avi _stamped_filename:=true -> 1466299931.584632829_out.avi
  - _filename:=$HOME/.ros/.avi _stamped_filename:=true -> /home/ubuntu/.ros/1466299931.584632829.avi
* Revert max_depth_range to default value for cvtColorForDisplay
* Contributors: Kentaro Wada, Vincent Rabaud

1.12.18 (2016-07-12)
--------------------
* Use image_transport::Subscriber aside from ros::Subscriber
* Refactor: Remove subscription of camera_info in video_recorder
* Add colormap options for displaying image topic
* Use CvtColorForDisplayOptions for cvtColorForDisplay
* Contributors: Kentaro Wada, Vincent Rabaud

1.12.17 (2016-07-11)
--------------------
* Fix timestamp to get correct fps in video_recorder
* Get correct fps in video_recorder.cpp
* Do dynamic scaling for float images
* Contributors: Kentaro Wada

1.12.16 (2016-03-19)
--------------------
* Remove code for roslib on .cfg files
  Closes `#185 <https://github.com/ros-perception/image_pipeline/issues/185>`_
* add cv::waitKey for opencv3 installed from source to fix freezing issue
* when no image is saved, do not save camera info
  When the images are not recorded because "save_all_image" is false and "save_image_service" is false, the frame count should not be incremented and the camera info should not be written to disk.
* Add std_srvs to catkin find_package()
* Contributors: Jeremy Kerfs, Jochen Sprickerhof, Kentaro Wada, Krishneel

1.12.15 (2016-01-17)
--------------------
* simplify the OpenCV dependency
* [image_view] Configure do_dynamic_scaling param with dynamic_reconfigure
* [image_view] Scale 16UC1 depth image
* fix compilation
* Extract images which are synchronized with message_filters
* [image_view] Show full path when failed to save image
* [image_view] Enable to specify transport with arg
* [image_view] feedback: no need threading for callback
* [image_view/image_view] Make as a node
* Added sensor_msgs::Image conversion to cv::Mat from rqt_image_view in
  order to be able to create videos from kinect depth images (cv_bridge
  currently doesn't support 16UC1 image encoding).
  Code adapted from:
  https://github.com/ros-visualization/rqt_common_plugins/blob/groovy-devel/rqt_image_view/src/rqt_image_view/image_view.cpp
* simplify OpenCV3 conversion
* use the color conversion for display from cv_bridge
* Contributors: Carlos Costa, Kentaro Wada, Vincent Rabaud

1.12.14 (2015-07-22)
--------------------
* reduce the differences between OpenCV2 and 3
* do not build GUIs on Android
  This fixes `#137 <https://github.com/ros-perception/image_pipeline/issues/137>`_
* Contributors: Vincent Rabaud

1.12.13 (2015-04-06)
--------------------

1.12.12 (2014-12-31)
--------------------
* Convert function to inline to avoid duplicates with image_transport
* Revert "remove GTK dependency"
  This reverts commit a6e15e796a40385fbbf8da05966aa47d179dcb46.
  Conflicts:
  image_view/CMakeLists.txt
  image_view/src/nodelets/disparity_nodelet.cpp
  image_view/src/nodes/stereo_view.cpp
* Revert "make sure waitKey is called after imshow"
  This reverts commit d13e3ed6af819459bca221ece779964a74beefac.
* Revert "brings back window_thread"
  This reverts commit 41a655e8e99910c13a3e7f1ebfdd083207cef76f.
* Contributors: Gary Servin, Vincent Rabaud

1.12.11 (2014-10-26)
--------------------
* brings back window_thread
  This fixes `#102 <https://github.com/ros-perception/image_pipeline/issues/102>`_ fully
* small optimizations
* add the image_transport parameter
* Contributors: Vincent Rabaud

1.12.10 (2014-09-28)
--------------------

1.12.9 (2014-09-21)
-------------------
* get code to compile with OpenCV3
  fixes `#96 <https://github.com/ros-perception/image_pipeline/issues/96>`_
* Contributors: Vincent Rabaud

1.12.8 (2014-08-19)
-------------------

1.12.6 (2014-07-27)
-------------------
* make sure waitKey is called after imshow
* remove GTK dependency
* small speedups
* Contributors: Vincent Rabaud

1.12.5 (2014-05-11)
-------------------
* image_view: Add depend on gtk2
* Contributors: Scott K Logan

1.12.4 (2014-04-28)
-------------------
* fixes `#65 <https://github.com/ros-perception/image_pipeline/issues/65>`_
* Contributors: Vincent Rabaud

1.12.3 (2014-04-12)
-------------------

1.12.2 (2014-04-08)
-------------------

1.12.1 (2014-04-06)
-------------------
* get proper opencv dependency
* Contributors: Vincent Rabaud

1.11.7 (2014-03-28)
-------------------
* Added requirement for core.
* Contributors: Jonathan J Hunt

1.11.3 (2013-10-06 20:21:55 +0100)
----------------------------------
- #41: allow image_saver to save image topics
- #40: use proper download URL
