execute_process(COMMAND "/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/gazebo_ros_pkgs/gazebo_ros/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/gazebo_ros_pkgs/gazebo_ros/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
