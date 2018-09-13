# Docker Build: keras-with-ros
# This file is auto-generated using docker-construct
FROM nvidia/cuda:8.0-cudnn5-devel-ubuntu16.04
LABEL :name="keras-with-ros"\
	:creator="Jason L. Owens <jason.l.owens.civ@mail.mil>"\
	:description="A Keras development environment with the following additional packages: PCL, mlpack"\
	:base="nvidia/cuda:8.0-cudnn5-devel-ubuntu16.04"
# COMPONENT: :mirrors / 1.0
RUN echo "deb mirror://mirrors.ubuntu.com/mirrors.txt xenial main restricted universe multiverse" > /etc/apt/sources.list && \
	echo "deb mirror://mirrors.ubuntu.com/mirrors.txt xenial-updates main restricted universe multiverse" >> /etc/apt/sources.list && \
	echo "deb mirror://mirrors.ubuntu.com/mirrors.txt xenial-security main restricted universe multiverse" >> /etc/apt/sources.list && \
	echo "deb mirror://mirrors.ubuntu.com/mirrors.txt xenial-proposed main restricted universe multiverse" >> /etc/apt/sources.list && \
	DEBIAN_FRONTEND=noninteractive apt-get update

SHELL ["/bin/bash", "-c"]
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

# COMPONENT: :openblas / latest
RUN DEBIAN_FRONTEND=noninteractive apt-get -y update && \
	apt-get -y upgrade && \
	apt-get -y install gfortran \
	libatlas-dev \
	libatlas-base-dev \
	libblas-dev \
	libflann-dev \
	libgfortran3 \
	libgfortran-4.8-dev \
	liblapack-dev

RUN echo "/opt/OpenBLAS/lib" > /etc/ld.so.conf.d/openblas.conf

WORKDIR /tmp
RUN git clone https://github.com/xianyi/OpenBLAS /tmp/openblas && \
	pushd /tmp/openblas && \
	LD_LIBRARY_PATH=/usr/lib/gcc/x86_64-linux-gnu/5:$LD_LIBRARY_PATH make -j $(nproc) NO_AFFINITY=1 USE_OPENMP=1 && \
	make -j $(nproc) install && \
	popd && \
	rm -rf /tmp/openblas

# COMPONENT: :python / 2.7
RUN DEBIAN_FRONTEND=noninteractive apt-get -y update && \
	apt-get -y upgrade && \
	apt-get -y install curl \
	python \
	python-dev

RUN curl https://bootstrap.pypa.io/get-pip.py | python

# COMPONENT: :boost / 1.63.0
#WORKDIR /tmp
#RUN wget https://sourceforge.net/projects/boost/files/boost/1.63.0/boost_1_63_0.tar.bz2 && \
#	echo "beae2529f759f6b3bf3f4969a19c2e9d6f0c503edcb2de4a61d1428519fcb3b0 boost_1_63_0.tar.bz2" | sha256sum -c - && \
#	tar xjf boost_1_63_0.tar.bz2 && \
#	pushd /tmp/boost_1_63_0 && \
#	./bootstrap.sh --prefix=/usr/local && \
#	./b2 -j $(nproc) install && \
#	popd && \
#	rm -rf boost_1_63_0.tar.bz2 /tmp/boost_1_63_0

# COMPONENT: :mlpack / 2.1.1
WORKDIR /tmp
RUN DEBIAN_FRONTEND=noninteractive apt-get -y update && \
	apt-get -y upgrade && \
	apt-get -y install libarmadillo-dev libboost-all-dev

RUN git clone https://github.com/mlpack/mlpack.git /tmp/mlpack && \
	pushd /tmp/mlpack && \
	git checkout tags/mlpack-2.1.1 && \
	popd && \
	pushd /tmp/mlpack && \
	mkdir -p build && \
	pushd build && \
	cmake -DCMAKE_INSTALL_PREFIX=/usr/local .. && \
	make -j $(nproc) install && \
	popd && \
	popd && \
	rm -rf /tmp/mlpack

# COMPONENT: :scipy / 0.18.1
RUN pip install -U scipy

# COMPONENT: :sklearn / 0.18.1
RUN pip install -U scikit-learn==0.18.1

# COMPONENT: :opengl / 1.0
RUN DEBIAN_FRONTEND=noninteractive apt-get -y update && \
	apt-get -y upgrade && \
	apt-get -y install xserver-xorg-dev \
	libxt-dev \
	mesa-utils \
	mesa-common-dev \
	mesa-utils-extra \
	libgl1-mesa-dev \
	libglapi-mesa

# COMPONENT: :java / 8
RUN echo oracle-java8-installer shared/accepted-oracle-license-v1-1 select true | /usr/bin/debconf-set-selections

RUN DEBIAN_FRONTEND=noninteractive apt-get -y install software-properties-common && \
	add-apt-repository -y ppa:webupd8team/java

RUN DEBIAN_FRONTEND=noninteractive apt-get -y update && \
	apt-get -y upgrade && \
	apt-get -y install oracle-java8-installer

RUN update-java-alternatives -s java-8-oracle

ENV JAVA_HOME=/usr/lib/jvm/java-8-oracle
# COMPONENT: :vtk / 7.1.0
RUN DEBIAN_FRONTEND=noninteractive apt-get -y update && \
	apt-get -y upgrade && \
	apt-get -y install doxygen

RUN git clone https://github.com/Kitware/VTK /tmp/vtk7.1.0 && \
	pushd /tmp/vtk7.1.0 && \
	git checkout tags/v7.1.0 && \
	popd && \
	pushd /tmp/vtk7.1.0 && \
	mkdir -p build && \
	pushd build && \
	cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo -DCMAKE_INSTALL_PREFIX=/usr/local -DBUILD_DOCUMENTATION=ON -DVTK_USE_CXX11_FEATURES=ON -DVTK_WRAP_JAVA=ON -DVTK_WRAP_PYTHON=ON .. && \
	make -j $(nproc) install && \
	popd && \
	popd && \
	rm -rf /tmp/vtk7.1.0

# COMPONENT: :skimage / 0.12.3
RUN pip install -U scikit-image

# COMPONENT: :keras / latest
RUN pip install -U PyYAML \
	h5py \
	jupyter \
	tensorflow-gpu \
	Keras \
	elephas

# COMPONENT: :pcl / 1.8.0
RUN DEBIAN_FRONTEND=noninteractive apt-get -y update && \
	apt-get -y upgrade && \
	apt-get -y install libeigen3-dev \
	libopenni-sensor-primesense0 \
	libopenni-sensor-primesense-dev \
	libopenni-dev \
	libopenni0 \
	openni-utils \
	libqhull-dev \
	libqhull7 \
	libopenni2-dev \
	openni2-utils

RUN git clone http://github.com/PointCloudLibrary/pcl.git /tmp/pcl1.8.0 && \
	pushd /tmp/pcl1.8.0 && \
	git checkout tags/pcl-1.8.0 && \
	popd && \
	pushd /tmp/pcl1.8.0 && \
	mkdir -p build && \
	pushd build && \
	cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo -DCMAKE_INSTALL_PREFIX=/usr/local .. && \
	make -j $(nproc) install && \
	popd && \
	popd && \
	rm -rf /tmp/pcl1.8.0

