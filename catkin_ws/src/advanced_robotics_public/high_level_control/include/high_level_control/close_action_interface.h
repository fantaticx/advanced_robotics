#include <ros/ros.h>
#include <vector>

#include <rosplan_action_interface/RPActionInterface.h>

#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <robot_door_closing/door_closeAction.h>

#ifndef CLOSE_ACTION_IF
#define CLOSE_ACTION_IF

namespace KCL_rosplan {

	class CloseActionInterface: public RPActionInterface
	{

	private:
	  actionlib::SimpleActionClient<robot_door_closing::door_closeAction> action_client_;

	public:

		/* constructor */
		CloseActionInterface(ros::NodeHandle &nh);

		/* listen to and process action_dispatch topic */
		bool concreteCallback(const rosplan_dispatch_msgs::ActionDispatch::ConstPtr& msg);
	};
}
#endif
