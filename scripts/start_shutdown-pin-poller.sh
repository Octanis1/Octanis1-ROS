#!/bin/bash
python -u /home/rover/Octanis1-ROS/scripts/shutdown-pin-poller.py &>> /var/log/octanis1-ros-scripts.log &
echo $! > /var/run/shutdown-pin-poller.pid
