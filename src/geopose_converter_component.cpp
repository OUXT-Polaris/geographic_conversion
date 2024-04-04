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

#include <geographic_conversion/geopose_converter_component.hpp>
#include <geometry_msgs/msg/pose_with_covariance.hpp>
#include <rclcpp_components/register_node_macro.hpp>
#include <std_msgs/msg/header.hpp>

namespace geographic_conversion
{
GeoposeConverterComponent::GeoposeConverterComponent(const rclcpp::NodeOptions & options)
: Node("geopose_converter_node", options)
{
  declare_parameter("map_frame", "map");
  get_parameter("map_frame", map_frame_);
  if (publish_covariance_) {
    pose_with_covariance_pub_ =
      this->create_publisher<geometry_msgs::msg::PoseWithCovarianceStamped>("/gps_pose", 1);
  } else {
    pose_pub_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("/gps_pose", 1);
  }
  declare_parameter("publish_covariance", false);
  get_parameter("publish_covariance", publish_covariance_);

  geopose_sub_ = this->create_subscription<geographic_msgs::msg::GeoPoseStamped>(
    "/geopose", 1,
    std::bind(&GeoposeConverterComponent::geoposeCallback, this, std::placeholders::_1));
}

void GeoposeConverterComponent::geoposeCallback(
  const geographic_msgs::msg::GeoPoseStamped::SharedPtr msg)
{
  pose_with_covariance_pub_->publish(convert_with_covariance(*msg));
}

auto GeoposeConverterComponent::convert(const geographic_msgs::msg::GeoPoseStamped & geopose) const
  -> geometry_msgs::msg::PoseStamped
{
  geodesy::UTMPose utm_pose = geodesy::UTMPose(geopose.pose);
  return geometry_msgs::build<geometry_msgs::msg::PoseStamped>()
    .header(
      std_msgs::build<std_msgs::msg::Header>().stamp(geopose.header.stamp).frame_id(map_frame_))
    .pose(geometry_msgs::build<geometry_msgs::msg::Pose>()
            .position(geometry_msgs::build<geometry_msgs::msg::Point>()
                        .x(utm_pose.position.northing)
                        .y(utm_pose.position.easting * -1)
                        .z(utm_pose.position.altitude))
            .orientation(utm_pose.orientation));
}

auto GeoposeConverterComponent::convert_with_covariance(
  const geographic_msgs::msg::GeoPoseStamped & geopose) const
  -> geometry_msgs::msg::PoseWithCovarianceStamped
{
  const auto pose = convert(geopose);
  return geometry_msgs::build<geometry_msgs::msg::PoseWithCovarianceStamped>()
    .header(pose.header)
    .pose(geometry_msgs::build<geometry_msgs::msg::PoseWithCovariance>().pose(pose.pose).covariance(
      {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
       0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1}));
}
}  // namespace geographic_conversion

RCLCPP_COMPONENTS_REGISTER_NODE(geographic_conversion::GeoposeConverterComponent)
