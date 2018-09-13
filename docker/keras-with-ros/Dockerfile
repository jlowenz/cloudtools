# Docker Build: keras-with-ros
# This file is auto-generated using docker-construct
FROM jlowenz/keras:1.0
LABEL :name="keras-with-ros"\
	:creator="Jason Owens <jason.l.owens.civ@mail.mil>"\
	:description="Add ROS Kinetic Base install to a Keras image"
# COMPONENT: :mirrors / 1.0
RUN echo "deb mirror://mirrors.ubuntu.com/mirrors.txt xenial main restricted universe multiverse" > /etc/apt/sources.list && \
	echo "deb mirror://mirrors.ubuntu.com/mirrors.txt xenial-updates main restricted universe multiverse" >> /etc/apt/sources.list && \
	echo "deb mirror://mirrors.ubuntu.com/mirrors.txt xenial-security main restricted universe multiverse" >> /etc/apt/sources.list && \
	echo "deb mirror://mirrors.ubuntu.com/mirrors.txt xenial-proposed main restricted universe multiverse" >> /etc/apt/sources.list && \
	DEBIAN_FRONTEND=noninteractive apt-get update

SHELL ["/bin/bash", "-c"]
# COMPONENT: :python / 2.7
RUN DEBIAN_FRONTEND=noninteractive apt-get -y update && \
	apt-get -y upgrade && \
	apt-get -y install curl \
	python \
	python-dev

RUN curl https://bootstrap.pypa.io/get-pip.py | python

# COMPONENT: :cppdev / 1.0
RUN DEBIAN_FRONTEND=noninteractive apt-get -y update && \
	apt-get -y upgrade && \
	apt-get -y install build-essential \
	cmake \
	curl \
	git \
	hashalot \
	mercurial \
	pkg-config \
	python \
	python-dev \
	wget

# COMPONENT: :ros / kinetic
RUN sh -c 'echo "deb http://packages.ros.org/ros/ubuntu xenial main" > /etc/apt/sources.list.d/ros-latest.list' && \
	apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net:80 --recv-key 421C365BD9FF1F717815A3895523BAEEB01FA116

RUN DEBIAN_FRONTEND=noninteractive apt-get -y update && \
	apt-get -y upgrade && \
	apt-get -y install ros-kinetic-ros-base \
	python-rosinstall

RUN rosdep init

RUN echo "source /opt/ros/kinetic/setup.bash" >> /etc/bash.bashrc

RUN pip install pathlib
RUN DEBIAN_FRONTEND=noninteractive apt-get -y update && apt-get -y install x11-apps sudo

# install VirtualGl 2.5.1
RUN apt-get update && apt-get install -y \
    libglu1-mesa-dev mesa-utils xterm libxv1 && \
    wget http://downloads.sourceforge.net/project/virtualgl/2.5.1/virtualgl_2.5.1_amd64.deb && \
    dpkg -i virtualgl_2.5.1_amd64.deb && \
    /opt/VirtualGL/bin/vglserver_config -config +s +f -t && \
    rm virtualgl_2.5.1_amd64.deb && \
    apt-get remove -y wget && \
    rm -rf /var/lib/apt/lists/*

LABEL com.nvidia.volumes.needed="nvidia_driver"
ENV PATH /usr/local/nvidia/bin:/opt/VirtualGL/bin:${PATH}
ENV LD_LIBRARY_PATH /usr/local/nvidia/lib:/usr/local/nvidia/lib64:${LD_LIBRARY_PATH}

RUN echo "/usr/local/lib/python2.7/site-packages" > /usr/lib/python2.7/dist-packages/vtk.pth

RUN DEBIAN_FRONTEND=noninteractive apt-get -y update && apt-get -y install gdb parallel
RUN pip install joblib seaborn

ADD .symrc /tmp/.symrc

RUN apt-get update && apt-get install -y \
    protobuf-compiler protobuf-c-compiler libprotoc-dev python-protobuf libprotobuf-dev
RUN apt-get update && apt-get install -y autoconf
# RUN mkdir -p /tmp/protobufs \
#     && cd /tmp/protobufs \
#     && curl -o protobufs.tar.gz -L https://github.com/google/protobuf/releases/download/v3.1.0/protobuf-cpp-3.1.0.tar.gz \
#     && mkdir -p protobuf \
#     && tar -zxvf protobufs.tar.gz -C /tmp/protobufs/protobuf --strip-components=1 \
#     && cd protobuf \
#     && ./autogen.sh \
#     && ./configure --prefix=/usr  \
#     && make -j16 \
#     && make install \
#     && ldconfig \
#     && cd && rm -rf /tmp/protobufs && rm -rf /tmp/protobufs.tar.gz

# COMPONENT: :user-entry / 1.0
ADD user_entrypoint.sh /usr/bin/user_entrypoint.sh
ENTRYPOINT ["/usr/bin/user_entrypoint.sh"]
