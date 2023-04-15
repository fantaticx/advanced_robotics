#include <high_level_control/open_action_interface.h>

namespace KCL_rosplan {

	OpenActionInterface::OpenActionInterface(ros::NodeHandle &nh) : action_client_("door_open", true) {
	}

	/* action dispatch callback */
	bool OpenActionInterface::concreteCallback(const rosplan_dispatch_msgs::ActionDispatch::ConstPtr& msg) {

		//TODO: Read the desired goal parameter and open the door by calling the action_client_
    // Also consider a failed door opening. 

		return true;
	}
} // close namespace

	/*-------------*/
	/* Main method */
	/*-------------*/

	int main(int argc, char **argv) {

		ros::init(argc, argv, "rosplan_open_action", ros::init_options::AnonymousName);
		ros::NodeHandle nh("~");

		// create PDDL action subscriber
		KCL_rosplan::OpenActionInterface rpti(nh);

		rpti.runActionInterface();

		return 0;
	}
