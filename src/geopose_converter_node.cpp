#include <geographic_conversion/geopose_converter.h>

// headers in ros
#include <ros/ros.h>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "geopose_converter_node");
    ros::NodeHandle nh;
    ros::NodeHandle pnh("~");
    geographic_conversion::GeoposeConverter converter(nh,pnh);
    ros::spin();
    return 0;
}