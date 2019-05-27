// Headers in this package
#include <geographic_conversion/geographic_conversion_server.h>

namespace geographic_conversion
{
    GeographicConversionServer::GeographicConversionServer(ros::NodeHandle nh,ros::NodeHandle pnh)
        : nh_(nh),pnh_(pnh),tf_listener_(tf_buffer_)
    {
        pnh_.param<std::string>("map_frame", map_frame_, "world");
    }

    GeographicConversionServer::~GeographicConversionServer()
    {

    }

    bool GeographicConversionServer::GeoPointToPoint(GeoPointToPoint::Request &req,GeoPointToPoint::Response &res)
    {
        geodesy::UTMPoint utm_point = geodesy::UTMPoint(req.geopoint);
        res.point.header.frame_id = map_frame_;
        res.point.header.stamp = req.stamp;
        res.point.point.x = utm_point.northing;
        res.point.point.y = utm_point.easting * -1;
        res.point.point.z = utm_point.altitude;
        return true;
    }

    bool GeographicConversionServer::PointToGeoPoint(PointToGeoPoint::Request &req,PointToGeoPoint::Response &res)
    {
        geometry_msgs::PointStamped point = req.point;
        if(point.header.frame_id != map_frame_)
        {
            geometry_msgs::TransformStamped transform_stamped;
            try
            {
                transform_stamped = tf_buffer_.lookupTransform(map_frame_, point.header.frame_id,ros::Time(0));
            }
            catch (tf2::TransformException &ex)
            {
                ROS_WARN("%s",ex.what());
                res.result = res.CONVERSION_FAILED;
                return false;
            }
            tf2::doTransform(point,point,transform_stamped);
        }
        double easting = point.point.y*-1;
        double northing = point.point.x;
        double altitude = point.point.z;
        char band = *req.mgrs_latitude_band.c_str();
        uint8_t zone = req.utm_longitude_zone;
        geodesy::UTMPoint utm_point = geodesy::UTMPoint(easting,northing,altitude,zone,band);
        res.geopoint = 	geodesy::toMsg(utm_point);
        res.result = res.CONVERSION_SUCCEEDED;
        return true;
    }
}