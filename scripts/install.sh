#!/bin/bash
# this script symlinks rosctl and installs an upstart script so that ros and a launchfile starts on boot

cp $(pwd -P)/ros-system-daemon.conf /etc/init/ros-system-daemon.conf
ln -s $(pwd -P)/rosctl /usr/sbin/rosctl
