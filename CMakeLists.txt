cmake_minimum_required(VERSION 3.0)
project(cloudtools)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

find_package(catkin REQUIRED COMPONENTS roscpp)

find_package(PCL 1.8 REQUIRED COMPONENTS
  common io visualization filters console segmentation)
find_package(Eigen3 REQUIRED)
find_package(Boost REQUIRED COMPONENTS
  system filesystem program_options REQUIRED)
find_package(Qt4 REQUIRED QtCore QtGui)
find_package(ANN REQUIRED)

set(CMAKE_CXX_STANDARD 17)

catkin_package(
  #  INCLUDE_DIRS include
  LIBRARIES medialskeleton
  #  CATKIN_DEPENDS pcl roscpp
  DEPENDS PCL)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
  ${QT4_INCLUDE_DIRS}
  ${ANN_INCLUDE_DIR})

link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

set(CMAKE_CXX_FLAGS "-fopenmp ${CMAKE_CXX_FLAGS}")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(src src/Algorithm)
add_library(medialskeleton
  src/Algorithm/Skeletonization.cpp
  src/Algorithm/Skeleton.cpp
  src/GlobalFunction.cpp
  src/Parameter.cpp
  src/ParameterMgr.cpp
  src/DataMgr.cpp)
target_link_libraries(medialskeleton ${PCL_LIBRARIES} Qt4::QtCore Qt4::QtGui ${ANN_LIBRARIES})

install(TARGETS medialskeleton
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
