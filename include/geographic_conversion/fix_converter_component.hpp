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

#ifndef GEOGRAPHIC_CONVERSION__FIX_CONVERTER_HPP_
#define GEOGRAPHIC_CONVERSION__FIX_CONVERTER_HPP_

//headers in ROS
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/nav_sat_fix.hpp>
#include <geometry_msgs/msg/point_stamped.hpp>
#include <geodesy/utm.h>

#if __cplusplus
extern "C" {
#endif

// The below macros are taken from https://gcc.gnu.org/wiki/Visibility and from
// demos/composition/include/composition/visibility_control.h at https://github.com/ros2/demos
#if defined _WIN32 || defined __CYGWIN__
#ifdef __GNUC__
#define GEOGRAPHIC_CONVERSION_FIX_CONVERTER_COMPONENTCOMPONENT_EXPORT __attribute__((dllexport))
#define GEOGRAPHIC_CONVERSION_FIX_CONVERTER_COMPONENTCOMPONENT_IMPORT __attribute__((dllimport))
#else
#define GEOGRAPHIC_CONVERSION_FIX_CONVERTER_COMPONENTCOMPONENT_EXPORT __declspec(dllexport)
#define GEOGRAPHIC_CONVERSION_FIX_CONVERTER_COMPONENTCOMPONENT_IMPORT __declspec(dllimport)
#endif
#ifdef GEOGRAPHIC_CONVERSION_FIX_CONVERTER_COMPONENTCOMPONENT_BUILDING_DLL
#define GEOGRAPHIC_CONVERSION_FIX_CONVERTER_COMPONENTCOMPONENT_PUBLIC \
  GEOGRAPHIC_CONVERSION_FIX_CONVERTER_COMPONENTCOMPONENT_EXPORT
#else
#define GEOGRAPHIC_CONVERSION_FIX_CONVERTER_COMPONENTCOMPONENT_PUBLIC \
  GEOGRAPHIC_CONVERSION_FIX_CONVERTER_COMPONENTCOMPONENT_IMPORT
#endif
#define GEOGRAPHIC_CONVERSION_FIX_CONVERTER_COMPONENTCOMPONENT_PUBLIC_TYPE \
  GEOGRAPHIC_CONVERSION_FIX_CONVERTER_COMPONENTCOMPONENT_PUBLIC
#define GEOGRAPHIC_CONVERSION_FIX_CONVERTER_COMPONENTCOMPONENT_LOCAL
#else
#define GEOGRAPHIC_CONVERSION_FIX_CONVERTER_COMPONENTCOMPONENT_EXPORT \
  __attribute__((visibility("default")))
#define GEOGRAPHIC_CONVERSION_FIX_CONVERTER_COMPONENTCOMPONENT_IMPORT
#if __GNUC__ >= 4
#define GEOGRAPHIC_CONVERSION_FIX_CONVERTER_COMPONENTCOMPONENT_PUBLIC \
  __attribute__((visibility("default")))
#define GEOGRAPHIC_CONVERSION_FIX_CONVERTER_COMPONENTCOMPONENT_LOCAL \
  __attribute__((visibility("hidden")))
#else
#define GEOGRAPHIC_CONVERSION_FIX_CONVERTER_COMPONENTCOMPONENT_PUBLIC
#define GEOGRAPHIC_CONVERSION_FIX_CONVERTER_COMPONENTCOMPONENT_LOCAL
#endif
#define GEOGRAPHIC_CONVERSION_FIX_CONVERTER_COMPONENTCOMPONENT_PUBLIC_TYPE
#endif

#if __cplusplus
}  // extern "C"
#endif

namespace geographic_conversion
{
    class FixConverterComponent
    {
    public:
    /*
        FixConverter(ros::NodeHandle nh,ros::NodeHandle pnh);
        ~FixConverter();
        geometry_msgs::PointStamped convert(sensor_msgs::NavSatFix fix);
    */
    private:
    /*
        ros::NodeHandle nh_;
        ros::NodeHandle pnh_;
        void fixCallback(const sensor_msgs::NavSatFix::ConstPtr msg);
        ros::Publisher point_pub_;
        ros::Subscriber fix_sub_;
        std::string map_frame_;
        std::string input_topic_;
    */
    };
}  // geographic_conversion

#endif  // GEOGRAPHIC_CONVERSION__FIX_CONVERTER_HPP_