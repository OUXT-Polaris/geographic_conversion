#ifndef GEOGRAPHIC_CONVERSION_GEOPATH_CONVERTER_H_INCLUDED
#define GEOGRAPHIC_CONVERSION_GEOPATH_CONVERTER_H_INCLUDED

//headers in ROS
#include <ros/ros.h>
#include <geographic_msgs/GeoPath.h>
#include <nav_msgs/Path.h>
#include <geodesy/utm.h>

namespace geographic_conversion
{
    class GeopathConverter
    {
    public:
        GeopathConverter(ros::NodeHandle nh,ros::NodeHandle pnh);
        ~GeopathConverter();
        nav_msgs::Path convert(geographic_msgs::GeoPath path);
    private:
        ros::NodeHandle nh_;
        ros::NodeHandle pnh_;
        std::string map_frame_;
        geometry_msgs::Point convertToPoint(geographic_msgs::GeoPoint point);
        void geoPathCallback(const geographic_msgs::GeoPath::ConstPtr path);
        ros::Subscriber geopath_sub_;
        ros::Publisher path_pub_;
    };
}

#endif  //GEOGRAPHIC_CONVERSION_GEOPATH_CONVERTER_H_INCLUDED