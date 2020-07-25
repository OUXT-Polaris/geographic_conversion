// Copyright (c) 2019 OUXT Polaris
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

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
        std::string input_topic_;
        geometry_msgs::Point convertToPoint(geographic_msgs::GeoPoint point);
        void geoPathCallback(const geographic_msgs::GeoPath::ConstPtr path);
        ros::Subscriber geopath_sub_;
        ros::Publisher path_pub_;
    };
}

#endif  //GEOGRAPHIC_CONVERSION_GEOPATH_CONVERTER_H_INCLUDED