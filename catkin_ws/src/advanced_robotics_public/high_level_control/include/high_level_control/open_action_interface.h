#include <ros/ros.h>
#include <vector>

#include <rosplan_action_interface/RPActionInterface.h>

#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <robot_door_opening/door_openAction.h>

#ifndef OPEN_ACTION_IF
#define OPEN_ACTION_IF

namespace KCL_rosplan {

	class OpenActionInterface: public RPActionInterface
	{

	private:
	  actionlib::SimpleActionClient<robot_door_opening::door_openAction> action_client_;

	public:

		/* constructor */
		OpenActionInterface(ros::NodeHandle &nh);

		/* listen to and process action_dispatch topic */
		bool concreteCallback(const rosplan_dispatch_msgs::ActionDispatch::ConstPtr& msg);
	};
}
#endif
