#include <ros/ros.h>
#include "std_msgs/String.h"
#include <stdlib.h>

#include <sstream>

#include "tutorial/ModString.h"


//  string to store the message
//  default initiation to "default msg"
std::string g_str("default msg");


/**
 * @brief      function to handle service
 *
 * @param      req   The request
 * @param      res   The response
 *
 * @return     returns true upon successful execution
 */
bool modify(tutorial::ModString::Request  &req,
            tutorial::ModString::Request  &res) {
  ROS_INFO("Service Call initiated");
  g_str = req.s;
  ROS_INFO("Message modification successful");
  return true;
}


int main(int argc, char **argv){

  ros::init(argc,argv,"talker");
  ros::NodeHandle nh;

  ros::Publisher pub = nh.advertise<std_msgs::String>("chatter",1000);


 ros::ServiceServer service = nh.advertiseService("mod_string", modify);
 //  variable to store loop frequency
 int rate(1);
 // Load parameter
 if (nh.hasParam("f")) {
   ROS_INFO("Parameter f available");
   if (nh.getParam("f", rate)) {
     ROS_INFO("Rewriting frequency \n");
   }
}


  ros::Rate loop_rate(10);

  int count = 0;
  std_msgs::String msg;
  std::stringstream ss;

  while (ros::ok())
  {

    ss << g_str << "\t" << count << "\n";
    msg.data = ss.str();
    ROS_INFO("%s", msg.data.c_str());
    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     */
    pub.publish(msg);
    ss.str("");
    ros::spinOnce();
    loop_rate.sleep();
    ++count;

  }
  return 0;
}
