cmake_minimum_required(VERSION 3.0.2)
project(teleop_key)

find_package(catkin REQUIRED COMPONENTS
  std_msgs
  rospy
  roscpp
)

catkin_package(
#  INCLUDE_DIRS include
  LIBRARIES teleop_key
  CATKIN_DEPENDS std_msgs rospy roscpp
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

add_executable(teleop_key_sub src/teleop_key_sub.cpp)
add_dependencies(teleop_key_sub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(teleop_key_sub ${BULLET_LIBRARIES} ${catkin_LIBRARIES} -lwiringPi)
