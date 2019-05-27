#ifndef GEOGRAPHIC_CONVERSION_GEOGRAPHIC_CONVERSION_SERVER_H_INCLUDED
#define GEOGRAPHIC_CONVERSION_GEOGRAPHIC_CONVERSION_SERVER_H_INCLUDED

// Headers in ROS
#include <ros/ros.h>
#include <geodesy/utm.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

// Headers in this package
#include <geographic_conversion/GeoPointToPoint.h>
#include <geographic_conversion/PointToGeoPoint.h>

namespace geographic_conversion
{
    class GeographicConversionServer
    {
    public:
        GeographicConversionServer(ros::NodeHandle nh,ros::NodeHandle pnh);
        ~GeographicConversionServer();
        bool GeoPointToPoint(GeoPointToPoint::Request &req,GeoPointToPoint::Response &res);
        bool PointToGeoPoint(PointToGeoPoint::Request &req,PointToGeoPoint::Response &res);
    private:
        const ros::NodeHandle nh_;
        const ros::NodeHandle pnh_;
        std::string map_frame_;
        tf2_ros::Buffer tf_buffer_;
        tf2_ros::TransformListener tf_listener_;
    };
}

#endif  //GEOGRAPHIC_CONVERSION_GEOGRAPHIC_CONVERSION_SERVER_H_INCLUDED