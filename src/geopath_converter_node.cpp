#include <geographic_conversion/geopath_converter.h>

// headers in ros
#include <ros/ros.h>

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "geopath_converter_node");
  ros::NodeHandle nh;
  ros::NodeHandle pnh("~");
  GeopathConverter converter(nh,pnh);
  ros::spin();
  return 0;
}