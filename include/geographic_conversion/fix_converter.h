#ifndef GEOGRAPHIC_CONVERSION_FIX_CONVERTER_H_INCLUDED
#define GEOGRAPHIC_CONVERSION_FIX_CONVERTER_H_INCLUDED

//headers in ROS
#include <ros/ros.h>

namespace geographic_conversion
{
    class FixConverter
    {
    public:
        FixConverter(ros::NodeHandle nh,ros::NodeHandle pnh);
        ~FixConverter();
    };
}

#endif  //GEOGRAPHIC_CONVERSION_FIX_CONVERTER_H_INCLUDED