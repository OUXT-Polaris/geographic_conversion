#ifndef GEOGRAPHIC_CONVERSION_GEOPOSE_CONVERTER_H_INCLUDED
#define GEOGRAPHIC_CONVERSION_GEOPOSE_CONVERTER_H_INCLUDED

// Headers in ROS
#include <ros/ros.h>
#include <geographic_msgs/GeoPoseStamped.h>
#include <geodesy/utm.h>
#include <geometry_msgs/PoseStamped.h>

namespace geographic_conversion
{
    class GeoposeConverter
    {
    public:
        GeoposeConverter(ros::NodeHandle nh,ros::NodeHandle pnh);
        ~GeoposeConverter();
    private:
        ros::NodeHandle nh_;
        ros::NodeHandle pnh_;
        void geoposeCallback(const geographic_msgs::GeoPoseStamped::ConstPtr msg);
        ros::Subscriber geopose_sub_;
        ros::Publisher pose_pub_;
        std::string input_topic_;
        std::string map_frame_;
        geometry_msgs::PoseStamped convert(geographic_msgs::GeoPoseStamped geopose);
    };
}

#endif  //GEOGRAPHIC_CONVERSION_GEOPOSE_CONVERTER_H_INCLUDED