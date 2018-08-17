#include "ros/ros.h"
#include "std_msgs/String.h"
#include "tutorial/ModString.h"

void pubCallback(const std_msgs::String::ConstPtr& msg){
  ROS_INFO("Receive: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("chatter",1000,pubCallback);

  ros::spin();
  return 0;
}
