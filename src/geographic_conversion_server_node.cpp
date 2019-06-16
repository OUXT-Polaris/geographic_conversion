// Headers in this package
#include <geographic_conversion/geographic_conversion_server.h>

// Headers in ros
#include <ros/ros.h>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "geographic_conversion_server_node");
    ros::NodeHandle nh;
    ros::NodeHandle pnh("~");
    using namespace geographic_conversion;
    GeographicConversionServer server(nh,pnh);
    ros::ServiceServer geopoint_to_point_server = pnh.advertiseService("geopoint_to_point", &GeographicConversionServer::GeoPointToPoint, &server);
    ros::ServiceServer point_to_geopoint_server = pnh.advertiseService("point_to_geopoint", &GeographicConversionServer::PointToGeoPoint, &server);
    ros::spin();
    return 0;
}