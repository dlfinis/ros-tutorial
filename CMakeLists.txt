cmake_minimum_required(VERSION 2.8.3)
project(tutorial)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  genmsg
)



## Generate services in the 'srv' folder
 add_service_files(
   FILES
   ModString.srv
)


## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
   std_msgs
 )


catkin_package()


###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS}
)

##################################################################################
# My Inclusions
##################################################################################

include_directories(include ${catkin_INCLUDE_DIRS})


add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})
add_dependencies(talker tutorial_generate_messages_cpp)


add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
add_dependencies(listener tutorial_generate_messages_cpp)

add_executable(modify src/listener.cpp)
target_link_libraries(modify ${catkin_LIBRARIES})
add_dependencies(modify tutorial_generate_messages_cpp)
