#!/bin/bash
# this script symlinks rosctl and installs an upstart script so that ros and a launchfile starts on boot

cp $(pwd -P)/ros-system-daemon.conf /etc/init/ros-system-daemon.conf
ln -s $(pwd -P)/a20-current-munin  /etc/munin/plugins/a20-current-munin
ln -s $(pwd -P)/a20-voltage-munin  /etc/munin/plugins/a20-voltage-munin
ln -s $(pwd -P)/a20-cputemp-munin  /etc/munin/plugins/a20-cputemp-munin
ln -s $(pwd -P)/rosctl /usr/sbin/rosctl
ln -s $(pwd -P)/shutdown-pin-poller-monit /etc/monit/conf-enabled/shutdown-pin-poller-monit
