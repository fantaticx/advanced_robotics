#include <high_level_control/move_action_interface.h>
#include <tf2/LinearMath/Quaternion.h>

/* The implementation of RPTutorial.h */
namespace KCL_rosplan {

	/* constructor */
	MoveActionInterface::MoveActionInterface(ros::NodeHandle &nh) : action_client_("move_base", true) 
	{
		
		// TODO: Prepare the mapping of the predicates to locations in the environment
		// 1) Define the predicate mapping in the yaml file (config/predicate_mapping.yaml) by assigning every predicate a 2D pose
		//    note: The yaml file is already loaded at startup as parameter
		// 2) Read the parameter ("/predicate_mapping") and store the mapped predicates in predicate_map_

	}

	/* action dispatch callback */
	bool MoveActionInterface::concreteCallback(const rosplan_dispatch_msgs::ActionDispatch::ConstPtr& msg) {

		// TODO: Handle the call of the move action here
		// - get predictae from action dispatch msg
		// - get predicate coordinates from its ID via the queried parameter 
		// - dispatch MoveBase action

	}
} // close namespace

	/*-------------*/
	/* Main method */
	/*-------------*/

	int main(int argc, char **argv) {

		ros::init(argc, argv, "rosplan_move_action", ros::init_options::AnonymousName);
		ros::NodeHandle nh("~");

		// create PDDL action subscriber
		KCL_rosplan::MoveActionInterface rpti(nh);

		rpti.runActionInterface();

		return 0;
	}