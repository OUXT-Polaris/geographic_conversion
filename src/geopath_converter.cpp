#include <geographic_conversion/geopath_converter.h>

namespace geographic_conversion
{
    GeopathConverter::GeopathConverter(ros::NodeHandle nh,ros::NodeHandle pnh)
    {
        nh_ = nh;
        pnh_ = pnh;
        pnh_.param<std::string>("map_frame", map_frame_, "world");
        path_pub_ = nh_.advertise<nav_msgs::Path>("path",1);
        geopath_sub_ = pnh_.subscribe("geopath",1,&GeopathConverter::geoPathCallback,this);
    }

    GeopathConverter::~GeopathConverter()
    {

    }

    geometry_msgs::Point GeopathConverter::convertToPoint(geographic_msgs::GeoPoint point)
    {
        geometry_msgs::Point to;
        geodesy::UTMPoint utm_point;
        geodesy::fromMsg(point,utm_point);
        to.x = utm_point.northing;
        to.y = utm_point.easting * -1;
        to.z = utm_point.altitude;
        return to;
    }

    nav_msgs::Path GeopathConverter::convert(geographic_msgs::GeoPath path)
    {
        nav_msgs::Path ret;
        ret.header.stamp = path.header.stamp;
        ret.header.frame_id = map_frame_;
        for(auto itr = path.poses.begin(); itr != path.poses.end(); itr++)
        {
            geometry_msgs::PoseStamped pose;
            pose.header.frame_id = map_frame_;
            pose.header.stamp = itr->header.stamp;
            pose.pose.position = convertToPoint(itr->pose.position);
            pose.pose.orientation = itr->pose.orientation;
        }
        return ret;
    }

    void GeopathConverter::geoPathCallback(const geographic_msgs::GeoPath::ConstPtr path)
    {
        path_pub_.publish(convert(*path));
        return;
    }
}