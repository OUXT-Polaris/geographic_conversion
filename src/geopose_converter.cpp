#include <geographic_conversion/geopose_converter.h>

namespace geographic_conversion
{
    GeoposeConverter::GeoposeConverter(ros::NodeHandle nh,ros::NodeHandle pnh)
    {
        nh_ = nh;
        pnh_ = pnh;
        pnh_.param<std::string>("map_frame", map_frame_, "world");
        pnh_.param<std::string>("input_topic", input_topic_, "/geopose");
        pose_pub_ = pnh_.advertise<geometry_msgs::PoseStamped>("pose",1);
        geopose_sub_ = nh_.subscribe(input_topic_,1,&GeoposeConverter::geoposeCallback,this);
    }

    GeoposeConverter::~GeoposeConverter()
    {

    }

    void GeoposeConverter::geoposeCallback(const geographic_msgs::GeoPoseStamped::ConstPtr msg)
    {
        pose_pub_.publish(convert(*msg));
    }

    geometry_msgs::PoseStamped GeoposeConverter::convert(geographic_msgs::GeoPoseStamped geopose)
    {
        geometry_msgs::PoseStamped pose;
        geodesy::UTMPose utm_pose = geodesy::UTMPose(geopose.pose);
        pose.header.frame_id = map_frame_;
        pose.header.stamp = geopose.header.stamp;
        pose.pose.position.x = utm_pose.position.northing;
        pose.pose.position.y = utm_pose.position.easting*-1;
        pose.pose.position.z = utm_pose.position.altitude;
        pose.pose.orientation = utm_pose.orientation;
        return pose;
    }
}