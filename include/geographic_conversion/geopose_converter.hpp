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