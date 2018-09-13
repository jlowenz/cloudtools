#!/bin/bash

cd /code/ws/mesh
if [[ -e install ]]; then
    source install/setup.bash
else
    source /opt/ros/kinetic/setup.bash
fi
catkin_make $@ -j $(nproc) -DCMAKE_BUILD_TYPE=RelWithDebInfo install
