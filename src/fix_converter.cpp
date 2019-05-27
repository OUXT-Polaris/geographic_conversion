#include <geographic_conversion/fix_converter.h>

namespace geographic_conversion
{
    FixConverter::FixConverter(ros::NodeHandle nh,ros::NodeHandle pnh)
    {
        nh_ = nh;
        pnh_ = pnh;
        pnh_.param<std::string>("map_frame", map_frame_, "world");
        point_pub_ = nh_.advertise<geometry_msgs::PointStamped>("/fix/point",1);
        fix_sub_ = pnh_.subscribe("fix",1,&FixConverter::fixCallback,this);
    }

    FixConverter::~FixConverter()
    {

    }

    void FixConverter::fixCallback(const sensor_msgs::NavSatFix::ConstPtr msg)
    {
        return;
    }
}