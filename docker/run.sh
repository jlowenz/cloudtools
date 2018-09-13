#!/usr/bin/env bash

BASE_CODE=$HOME/dev
DATA_DIR=/home/jlowens/data

DOCKER_IP=$(ifconfig docker0 | grep 'inet addr' | sed -re's/.*inet addr:([0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}).*/\1/')

CMD=${@:-"/bin/bash"}
#xhost +$DOCKER_IP
xhost +
docker run --rm -it --runtime=nvidia \
	      --net=host \
	      -p 127.0.0.1:7777:8888 \
		    -v /usr/lib/nvidia-396:/usr/lib/nvidia-396 \
	      -v $BASE_CODE:/code \
	      -v $DATA_DIR:/data \
	      -v $HOME/.Xauthority:/home/user/.Xauthority:rw \
        -v /dev/dri/card0:/dev/dri/card0:rw \
	      -e LOCAL_USER_ID=$(id -u) \
	      -e LOCAL_GROUP_ID=$(id -g) \
	      -e DISPLAY="$DISPLAY" \
	      --privileged \
	      -v /tmp/.X11-unix:/tmp/.X11-unix:rw \
	      jlowenz/keras-with-ros-psn:cuda9.0 $CMD
#        jlowenz/toposlam-env:1.0 $CMD
xhost -
