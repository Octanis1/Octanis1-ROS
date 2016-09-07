#!/bin/bash
export PYTHONPATH=/opt/ros/kinetic/lib/python2.7/dist-packages
/usr/bin/python -u /home/rover/Octanis1-ROS/scripts/shutdown-pin-poller.py &>> /var/log/octanis1-ros-scripts.log &
echo $! > /var/run/shutdown-pin-poller.pid
