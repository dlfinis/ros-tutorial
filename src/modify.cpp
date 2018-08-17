#include "ros/ros.h"
#include "std_msgs/String.h"
#include "tutorial/ModString.h"


int main(int argc, char **argv) {

 ros::init(argc, argv, "modify");
  ros::NodeHandle n;

  /**
 * This creates a client for the service.
 *  The ros::ServiceClient object is used to call the service later on.
 */
ros::ServiceClient client =
n.serviceClient<tutorial::ModString>("mod_string");

tutorial::ModString srv;
// Load parameter
if (n.hasParam("msg")) {
  ROS_INFO("Parameter msg available");
  if (!n.getParam("msg", srv.request.s)) {
    ROS_INFO("Error getting message \n");
    return 1;
  }
}
//  This actually calls the service
if (client.call(srv)) {
  ROS_INFO("Successfully modified");
} else {
  ROS_ERROR("Failed to call service mod_string");
  return 1;
}
return 0;
}
