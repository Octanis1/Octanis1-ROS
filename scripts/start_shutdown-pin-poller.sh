#!/bin/bash
python -u ${HOME}/Octanis1-ROS/scripts/shutdown-pin-poller.py &>> /var/log/octanis1-ros-scripts.log &
echo $! > /var/run/shutdown-pin-poller.pid
