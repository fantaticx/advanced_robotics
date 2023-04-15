## Setting up ROS

- Requirements: Ubuntu 20.04 or higher. Please be aware that we recommend to use Ubuntu 20.04 with ROS Noetic, as compilation errors with Ubuntu 18.04/ROS Melodic may occur!

- Ubuntu 20.04 or equivalent: Install ROS Noetic as described in the  [ROS Installation Guide](http://wiki.ros.org/noetic/Installation/Ubuntu). Install the full desktop version (`ros-noetic-desktop-full`)

- Create a new folder structure in your home directory:

`mkdir -p catkin_ws/src`

- Build you empty workspace

`cd catkin_ws/ && catkin_make`

- Add your setup script to your bashrc

`echo "source ~/catkin_ws/devel/setup.bash" >> ~/.bashrc`

- Don't forget to `source ~/.bashrc` or to reopen the terminal for the updated bash file to be loaded

## Setting up the Assignment Repository

- Clone this repository into the src folder.

- For Melodic: Clone the [ROSPlan github repo](https://github.com/KCL-Planning/ROSPlan) into the src folder

`git clone https://github.com/KCL-Planning/ROSPlan.git`

- For Noetic: the [ROSPlan branch](https://github.com/KCL-Planning/ROSPlan) into the src folder

`git clone -b noetic-devel https://github.com/oscar-lima/ROSPlan.git`

- Install ROS dependencies (in `catkin_ws/`):

`rosdep install --from-paths src --ignore-src -r -y`

- In this repo (`catkin_ws/src/advanced_robotics_public/`), execute

`sudo bash install`

- Build this repo (in `catkin_ws/`)

`catkin_make`

## Troubleshooting

- In ROS Melodic: A potential build error may occur regarding `signals` from the *Boost* library. In this case, you need to add the signals component into `occupancy_grid_utils/CMakeLists.txt` (line 15) such that: `find_package(Boost REQUIRED COMPONENTS system signals python)`

## Launching

- Launching Gazebo Simulation:

`roslaunch robot_gazebo platform_building.launch`

You can set the desired tf tree branch for testing your implementation by setting the `tf_base_link` argument: `base_link` sets the robot onto the odometry tf (default), `base_link_real` sets the robot onto the ground truth,  `base_link_pf` sets the transformation from your particle filter (Ass1), `base_link_g2o` sets transforms to the map frame according your graph based mapping approach (Ass2). E.g. you can launch the robot using ground truth data by executing:

`roslaunch robot_gazebo platform_building.launch tf_base_link:=base_link_real`

- Launching Keyboard Control ([Check here for control keys](http://wiki.ros.org/teleop_twist_keyboard)):

`roslaunch robot_control teleop_keyboard.launch`

- Launching RViz:

`roslaunch robot_gazebo rviz.launch`


