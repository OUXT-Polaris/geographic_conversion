cmake_minimum_required(VERSION 3.8)
project(geographic_conversion)

find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

ament_auto_add_library(geopose_converter_component SHARED
 src/geopose_converter_component.cpp)

ament_auto_add_library(geopath_converter_component SHARED
 src/geopath_converter_component.cpp)

ament_auto_add_library(fix_converter_component SHARED
 src/fix_converter_component.cpp) 

rclcpp_components_register_nodes(geopath_converter_component "geographic_conversion::GeopathConverterComponent")
rclcpp_components_register_nodes(fix_converter_component "geographic_conversion::FixConverterComponent")
rclcpp_components_register_nodes(geopose_converter_component "geographic_conversion::GeoposeConverterComponent")

install(TARGETS
  geopath_converter_component
  fix_converter_component
  geopose_converter_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

ament_export_libraries(geopath_converter_component)
ament_export_libraries(fix_converter_component)
ament_export_libraries(geopose_converter_component)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_auto_package()