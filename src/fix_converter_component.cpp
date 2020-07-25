#include <geographic_conversion/fix_converter.h>

namespace geographic_conversion
{
    /*
    FixConverter::FixConverter(ros::NodeHandle nh,ros::NodeHandle pnh)
    {
        nh_ = nh;
        pnh_ = pnh;
        pnh_.param<std::string>("map_frame", map_frame_, "world");
        pnh_.param<std::string>("input_topic", input_topic_, "/fix");
        point_pub_ = nh_.advertise<geometry_msgs::PointStamped>(input_topic_+"/position",1);
        fix_sub_ = pnh_.subscribe(input_topic_,1,&FixConverter::fixCallback,this);
    }

    FixConverter::~FixConverter()
    {

    }

    void FixConverter::fixCallback(const sensor_msgs::NavSatFix::ConstPtr msg)
    {
        geographic_msgs::GeoPoint geopoint;
        geopoint.longitude = msg->longitude;
        geopoint.latitude = msg->latitude;
        geopoint.altitude = msg->altitude;
        geodesy::UTMPoint utm_point = geodesy::UTMPoint(geopoint);
        geometry_msgs::PointStamped point;
        point.header.frame_id = map_frame_;
        point.header.stamp = msg->header.stamp;
        point.point.x = utm_point.northing;
        point.point.y = utm_point.easting * -1;
        point.point.z = utm_point.altitude;
        point_pub_.publish(point);
        return;
    }
    */
}