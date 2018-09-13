#!/bin/bash

cd /code/ws/mesh
source install/setup.bash
#exec rosrun cloudtools pcd_skeleton $@
exec rosrun --prefix 'gdb -ex run --args' cloudtools pcd_skeleton $@
