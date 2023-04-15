# Launching your Exploration Cascade for Ass4

- Launch Gazebo Simulation:

`roslaunch robot_gazebo platform_building.launch tf_odom_frame:=odom`

- Launch the Navigation and Mapping Nodes:

`roslaunch frontier_exploration navigation.launch`

- Launch RViz for ROS visualization:

`roslaunch robot_gazebo rviz.launch`

- Start your exploration cascade:

`rosrun frontier_exploration frontier_exploration_node`

