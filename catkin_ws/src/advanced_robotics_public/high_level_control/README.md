# Launching your high level implementation for Ass4

- Launch Gazebo Simulation:

`roslaunch robot_gazebo platform_building_doors.launch tf_base_link:=base_link_real`

- Launch RViz for ROS visualization (optional):

`roslaunch robot_gazebo rviz.launch`

- Start ROSPLAN (also launches the move base):

`roslaunch high_level_control rosplan.launch`

- Start the high_level control by calling:

`rosrun high_level_control start_planning.sh`

