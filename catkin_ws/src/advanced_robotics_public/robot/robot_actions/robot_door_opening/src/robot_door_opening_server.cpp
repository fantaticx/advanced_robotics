#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <robot_door_opening/door_openAction.h>
#include "gazebo_msgs/DeleteModel.h"
#include <random>


class DoorOpenAction
{
protected:

  ros::NodeHandle nh_;
  actionlib::SimpleActionServer<robot_door_opening::door_openAction> as_;
  std::string action_name_;
  robot_door_opening::door_openFeedback feedback_;
  robot_door_opening::door_openResult result_;
  float failure_probability = 0.2;
  bool failed = false;
  
public:

  DoorOpenAction(std::string name):
    as_(nh_, name, boost::bind(&DoorOpenAction::executeCB, this, _1), false), action_name_(name)
    {
      as_.start();
    }
    
  ~DoorOpenAction(void)
  {
  }
  
  void executeCB(const robot_door_opening::door_openGoalConstPtr &goal)
  {
    ROS_INFO("working...");
    feedback_.status.clear();
    feedback_.status.push_back(0);
    as_.publishFeedback(feedback_);
    feedback_.status.push_back(1);
    
    ros::ServiceClient client = nh_.serviceClient<gazebo_msgs::DeleteModel>("gazebo/delete_model");
    gazebo_msgs::DeleteModel srv;
    srv.request.model_name = goal->door_name;
    
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<float> distr(0, 1);
    
    failed = distr(eng) < failure_probability;
    
    
    result_.status = "No door found with this name: " + srv.request.model_name;
    if (failed == false){
      if (srv.request.model_name == "door1"){
        client.call(srv);
        result_.status = "success"; 
      } else if (srv.request.model_name == "door2"){
        client.call(srv);
        result_.status = "success";
      } else if (srv.request.model_name == "door3"){
        client.call(srv);
        result_.status = "success";
      } else if (srv.request.model_name == "door4"){
        client.call(srv);
        result_.status = "success";
      } else if (srv.request.model_name == "door5"){
        client.call(srv);
        result_.status = "success";
      } else if (srv.request.model_name == "door6"){
        client.call(srv);
        result_.status = "success";
      } else{
      result_.status = "failed due to unknown door name";
    }
    } else{
    result_.status = "failed to open door, please retry";
    }
   as_.setSucceeded(result_);
   ROS_INFO("finished.");
  }
    
};


int main(int argc, char** argv)
{
  ros::init(argc, argv, "door_open");
  DoorOpenAction door_open("door_open");
  ros::spin();
  return 0;
}
