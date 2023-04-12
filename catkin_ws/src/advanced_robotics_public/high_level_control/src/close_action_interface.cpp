#include <high_level_control/close_action_interface.h>

/* The implementation of RPTutorial.h */
namespace KCL_rosplan {

	CloseActionInterface::CloseActionInterface(ros::NodeHandle &nh) : action_client_("door_close", true) 
  {
	}

	/* action dispatch callback */
	bool CloseActionInterface::concreteCallback(const rosplan_dispatch_msgs::ActionDispatch::ConstPtr& msg) {
    //TODO: Read the desired goal parameter and close the door by calling the action_client_
    // Also consider a failed door opening. 

		return true;
	}
} // close namespace

	/*-------------*/
	/* Main method */
	/*-------------*/

	int main(int argc, char **argv) {

		ros::init(argc, argv, "rosplan_close_action", ros::init_options::AnonymousName);
		ros::NodeHandle nh("~");

		// create PDDL action subscriber
		KCL_rosplan::CloseActionInterface rpti(nh);

		rpti.runActionInterface();

		return 0;
	}
