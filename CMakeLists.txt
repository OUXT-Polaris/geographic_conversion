cmake_minimum_required(VERSION 2.8.3)
project(geographic_conversion)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  geodesy
  roscpp
  nav_msgs
  sensor_msgs
  message_generation
  geometry_msgs
  geographic_msgs
  tf2_ros
  tf2_geometry_msgs
)

add_service_files(
  FILES
  GeoPointToPoint.srv
  PointToGeoPoint.srv
)

generate_messages(
  DEPENDENCIES
  geographic_msgs
  geometry_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES geographic_conversion
  CATKIN_DEPENDS geodesy roscpp nav_msgs message_generation geometry_msgs geographic_msgs tf2_ros tf2_geometry_msgs
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

# convert geopath to path
add_executable(geopath_converter_node src/geopath_converter_node.cpp src/geopath_converter.cpp)
target_link_libraries(geopath_converter_node ${catkin_LIBRARIES})

# convert geopose to posestamped
add_executable(geopose_converter_node src/geopose_converter_node.cpp src/geopose_converter.cpp)
target_link_libraries(geopose_converter_node ${catkin_LIBRARIES})

# convert fix to pointstamped
add_executable(fix_converter_node src/fix_converter_node.cpp src/fix_converter.cpp)
target_link_libraries(fix_converter_node ${catkin_LIBRARIES})

# convert lat/lon conversion server
add_executable(geographic_conversion_server_node src/geographic_conversion_server_node.cpp src/geographic_conversion_server.cpp)
target_link_libraries(geographic_conversion_server_node ${catkin_LIBRARIES})
add_dependencies(geographic_conversion_server_node geographic_conversion_generate_messages_cpp)

# install executables
install(TARGETS geopath_converter_node geopose_converter_node fix_converter_node geographic_conversion_server_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

# install headers
install(DIRECTORY include
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)

foreach(dir srv launch)
  install(DIRECTORY ${dir}/
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/${dir})
endforeach(dir)
