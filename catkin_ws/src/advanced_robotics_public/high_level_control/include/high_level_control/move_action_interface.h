#include <ros/ros.h>
#include <vector>
#include <map>
#include <geometry_msgs/PoseStamped.h>
#include <rosplan_action_interface/RPActionInterface.h>
#include <actionlib/client/simple_action_client.h>
#include <move_base_msgs/MoveBaseAction.h>

#ifndef MOVE_ACTION_IF
#define MOVE_ACTION_IF

namespace KCL_rosplan {

	class MoveActionInterface: public RPActionInterface
	{

	private:
  	actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> action_client_;
	  std::map<std::string, geometry_msgs::PoseStamped> predicate_map_;

	public:

		/* constructor */
		MoveActionInterface(ros::NodeHandle &nh);

		/* listen to and process action_dispatch topic */
		bool concreteCallback(const rosplan_dispatch_msgs::ActionDispatch::ConstPtr& msg);
	};
}
#endif