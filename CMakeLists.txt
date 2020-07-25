cmake_minimum_required(VERSION 3.5)
project(geographic_conversion)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(geographic_msgs REQUIRED)
find_package(geodesy REQUIRED)

include_directories(
  include
)

add_library(fix_converter_component SHARED
  src/fix_converter_component.cpp
)
target_compile_definitions(fix_converter_component
  PRIVATE "nmea_to_geopose_nmea_to_geopose_COMPONENT_BUILDING_DLL")
ament_target_dependencies(nmea_to_geopose_component
  rclcpp
  rclcpp_components
  nmea_msgs
  geodesy
  geographic_msgs
  quaternion_operation)
rclcpp_components_register_nodes(nmea_to_geopose_component
  "nmea_geopose::NmeaToGeoPoseComponent")

# convert geopath to path
#add_executable(geopath_converter_node src/geopath_converter_node.cpp src/geopath_converter.cpp)
#target_link_libraries(geopath_converter_node ${catkin_LIBRARIES})

# convert geopose to posestamped
#add_executable(geopose_converter_node src/geopose_converter_node.cpp src/geopose_converter.cpp)
#target_link_libraries(geopose_converter_node ${catkin_LIBRARIES})

# convert fix to pointstamped
#add_executable(fix_converter_node src/fix_converter_node.cpp src/fix_converter.cpp)
#target_link_libraries(fix_converter_node ${catkin_LIBRARIES})

# convert lat/lon conversion server
#add_executable(geographic_conversion_server_node src/geographic_conversion_server_node.cpp src/geographic_conversion_server.cpp)
#target_link_libraries(geographic_conversion_server_node ${catkin_LIBRARIES})
#add_dependencies(geographic_conversion_server_node geographic_conversion_generate_messages_cpp)

# install executables
#install(TARGETS geopath_converter_node geopose_converter_node fix_converter_node geographic_conversion_server_node
#  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
#  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
#)

# install headers
install(
  DIRECTORY "include/"
  DESTINATION include
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_export_include_directories(include)
ament_package()