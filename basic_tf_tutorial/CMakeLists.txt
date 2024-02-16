cmake_minimum_required(VERSION 3.0.2)
project(basic_tf_tutorial)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  tf
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES basic_tf_tutorial
#  CATKIN_DEPENDS roscpp
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(basic_tf_node src/basic_tf.cpp)
target_link_libraries(basic_tf_node ${catkin_LIBRARIES})

