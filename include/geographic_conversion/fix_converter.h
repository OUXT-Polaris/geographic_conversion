#ifndef GEOGRAPHIC_CONVERSION_FIX_CONVERTER_H_INCLUDED
#define GEOGRAPHIC_CONVERSION_FIX_CONVERTER_H_INCLUDED

//headers in ROS
#include <ros/ros.h>
#include <sensor_msgs/NavSatFix.h>
#include <geometry_msgs/PointStamped.h>
#include <geodesy/utm.h>

namespace geographic_conversion
{
    class FixConverter
    {
    public:
        FixConverter(ros::NodeHandle nh,ros::NodeHandle pnh);
        ~FixConverter();
        geometry_msgs::PointStamped convert(sensor_msgs::NavSatFix fix);
    private:
        ros::NodeHandle nh_;
        ros::NodeHandle pnh_;
        void fixCallback(const sensor_msgs::NavSatFix::ConstPtr msg);
        ros::Publisher point_pub_;
        ros::Subscriber fix_sub_;
        std::string map_frame_;
        std::string input_topic_;
    };
}

#endif  //GEOGRAPHIC_CONVERSION_FIX_CONVERTER_H_INCLUDED