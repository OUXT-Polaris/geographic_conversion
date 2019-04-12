#include <geographic_conversion/geopath_converter.h>

GeopathConverter::GeopathConverter(ros::NodeHandle nh,ros::NodeHandle pnh)
{
    nh_ = nh;
    pnh_ = pnh;
    pnh_.param<std::string>("world_frame", world_frame_, "world");
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
    to.y = utm_point.easting;
    to.z = utm_point.altitude;
    return to;
}

void GeopathConverter::geoPathCallback(const geographic_msgs::GeoPath::ConstPtr path)
{
    nav_msgs::Path msg;
    msg.header.stamp = path->header.stamp;
    msg.header.frame_id = world_frame_;
    for(auto itr = path->poses.begin(); itr != path->poses.end(); itr++)
    {
        geometry_msgs::PoseStamped pose;
        pose.header.frame_id = world_frame_;
        pose.header.stamp = itr->header.stamp;
        pose.pose.position = convertToPoint(itr->pose.position);
        pose.pose.orientation = itr->pose.orientation;
    }
    path_pub_.publish(msg);
    return;
}