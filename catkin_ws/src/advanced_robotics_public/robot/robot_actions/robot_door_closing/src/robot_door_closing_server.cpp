#include <ros/ros.h>
#include <ros/package.h>
#include <actionlib/server/simple_action_server.h>
#include <robot_door_closing/door_closeAction.h>
#include "gazebo_msgs/SpawnModel.h"
#include <fstream>
#include <sstream>
#include <random>


class DoorCloseAction
{
protected:

  ros::NodeHandle nh_;
  actionlib::SimpleActionServer<robot_door_closing::door_closeAction> as_;
  std::string action_name_;
  robot_door_closing::door_closeFeedback feedback_;
  robot_door_closing::door_closeResult result_;
  float failure_probability = 0.2;
  bool failed = false;
  
public:

  DoorCloseAction(std::string name):
    as_(nh_, name, boost::bind(&DoorCloseAction::executeCB, this, _1), false), action_name_(name)
    {
      as_.start();
    }
    
  ~DoorCloseAction(void)
  {
  }
  
  void executeCB(const robot_door_closing::door_closeGoalConstPtr &goal)
  {
    ROS_INFO("working...");
    feedback_.status.clear();
    feedback_.status.push_back(0);
    as_.publishFeedback(feedback_);
    feedback_.status.push_back(1);
    
    std::string package_name = "robot_door_closing";
    std::string model_path = ros::package::getPath(package_name) + "/models/simple_door/model.sdf";
    std::ifstream t(model_path);
    std::stringstream buffer;
    buffer << t.rdbuf();
    std::string model_xml = buffer.str();
    
    ros::ServiceClient client = nh_.serviceClient<gazebo_msgs::SpawnModel>("gazebo/spawn_sdf_model");
    gazebo_msgs::SpawnModel srv;
    srv.request.model_xml = model_xml;
    srv.request.model_name = goal->door_name;
    
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<float> distr(0, 1);
    
    failed = distr(eng) < failure_probability;
    
    result_.status = "No door found with this name: " + srv.request.model_name;
    if (failed == false){
      if (srv.request.model_name == "door1"){
        srv.request.initial_pose.position.x = -11.6573;
        srv.request.initial_pose.position.y = 7.92765;
        srv.request.initial_pose.position.z = 1.0;
        client.call(srv);
        result_.status = "success"; 
      } else if (srv.request.model_name == "door2"){
        srv.request.initial_pose.position.x = 4.76747;
        srv.request.initial_pose.position.y = 3.7001;
        srv.request.initial_pose.position.z = 1.0;
        srv.request.initial_pose.orientation.x = 0.0;
        srv.request.initial_pose.orientation.y = 0.0;
        srv.request.initial_pose.orientation.z = 0.7071;
        srv.request.initial_pose.orientation.w = 0.7071;
        client.call(srv);
        result_.status = "success";
      } else if (srv.request.model_name == "door3"){
        srv.request.initial_pose.position.x = 2.9477;
        srv.request.initial_pose.position.y = 2.5751;
        srv.request.initial_pose.position.z = 1.0;
        client.call(srv);
        result_.status = "success"; 
      } else if (srv.request.model_name == "door4"){
        srv.request.initial_pose.position.x = -3.1065;
        srv.request.initial_pose.position.y = 1.7675;
        srv.request.initial_pose.position.z = 1.0;
        client.call(srv);
        result_.status = "success";
    } else if (srv.request.model_name == "door5"){
        srv.request.initial_pose.position.x = -5.9957;
        srv.request.initial_pose.position.y = 0.93;
        srv.request.initial_pose.position.z = 1.0;
        srv.request.initial_pose.orientation.x = 0.0;
        srv.request.initial_pose.orientation.y = 0.0;
        srv.request.initial_pose.orientation.z = 0.7071;
        srv.request.initial_pose.orientation.w = 0.7071;
        client.call(srv);
        result_.status = "success"; 
      } else if (srv.request.model_name == "door6"){
        srv.request.initial_pose.position.x = 2.7375;
        srv.request.initial_pose.position.y = -7.2721;
        srv.request.initial_pose.position.z = 1.0;
        client.call(srv);
        result_.status = "success";
    }
    else{
      result_.status = "failed";
    }
    
    ROS_INFO("finished.");
    as_.setSucceeded(result_);
  }
 }    
};


int main(int argc, char** argv)
{
  ros::init(argc, argv, "door_close");
  DoorCloseAction door_close("door_close");
  ros::spin();
  return 0;
}
