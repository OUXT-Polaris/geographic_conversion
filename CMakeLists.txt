cmake_minimum_required(VERSION 2.8.3)
project(geographic_conversion)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  geodesy
  roscpp
  nav_msgs
  sensor_msgs
)

catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES geographic_conversion
  CATKIN_DEPENDS geodesy roscpp nav_msgs
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(geopath_converter_node src/geopath_converter_node.cpp src/geopath_converter.cpp)
target_link_libraries(geopath_converter_node ${catkin_LIBRARIES})

add_executable(fix_converter_node src/fix_converter_node.cpp src/fix_converter.cpp)
target_link_libraries(fix_converter_node ${catkin_LIBRARIES})

install(TARGETS geopath_converter_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)