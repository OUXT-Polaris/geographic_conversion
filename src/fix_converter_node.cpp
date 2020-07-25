#include <geographic_conversion/fix_converter.hpp>

// headers in ros
#include <ros/ros.h>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "fix_converter_node");
    ros::NodeHandle nh;
    ros::NodeHandle pnh("~");
    geographic_conversion::FixConverter converter(nh,pnh);
    ros::spin();
    return 0;
}