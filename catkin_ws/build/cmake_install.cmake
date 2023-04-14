# Install script for directory: /home/thomas/Documents/university/ar/catkin_ws/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/thomas/Documents/university/ar/catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
        file(MAKE_DIRECTORY "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
      endif()
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin")
        file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin" "")
      endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/thomas/Documents/university/ar/catkin_ws/install/_setup_util.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/thomas/Documents/university/ar/catkin_ws/install" TYPE PROGRAM FILES "/home/thomas/Documents/university/ar/catkin_ws/build/catkin_generated/installspace/_setup_util.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/thomas/Documents/university/ar/catkin_ws/install/env.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/thomas/Documents/university/ar/catkin_ws/install" TYPE PROGRAM FILES "/home/thomas/Documents/university/ar/catkin_ws/build/catkin_generated/installspace/env.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/thomas/Documents/university/ar/catkin_ws/install/setup.bash;/home/thomas/Documents/university/ar/catkin_ws/install/local_setup.bash")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/thomas/Documents/university/ar/catkin_ws/install" TYPE FILE FILES
    "/home/thomas/Documents/university/ar/catkin_ws/build/catkin_generated/installspace/setup.bash"
    "/home/thomas/Documents/university/ar/catkin_ws/build/catkin_generated/installspace/local_setup.bash"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/thomas/Documents/university/ar/catkin_ws/install/setup.sh;/home/thomas/Documents/university/ar/catkin_ws/install/local_setup.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/thomas/Documents/university/ar/catkin_ws/install" TYPE FILE FILES
    "/home/thomas/Documents/university/ar/catkin_ws/build/catkin_generated/installspace/setup.sh"
    "/home/thomas/Documents/university/ar/catkin_ws/build/catkin_generated/installspace/local_setup.sh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/thomas/Documents/university/ar/catkin_ws/install/setup.zsh;/home/thomas/Documents/university/ar/catkin_ws/install/local_setup.zsh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/thomas/Documents/university/ar/catkin_ws/install" TYPE FILE FILES
    "/home/thomas/Documents/university/ar/catkin_ws/build/catkin_generated/installspace/setup.zsh"
    "/home/thomas/Documents/university/ar/catkin_ws/build/catkin_generated/installspace/local_setup.zsh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/thomas/Documents/university/ar/catkin_ws/install/.rosinstall")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/thomas/Documents/university/ar/catkin_ws/install" TYPE FILE FILES "/home/thomas/Documents/university/ar/catkin_ws/build/catkin_generated/installspace/.rosinstall")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/thomas/Documents/university/ar/catkin_ws/build/gtest/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/gazebo_ros_pkgs/gazebo_dev/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/gazebo_ros_pkgs/gazebo_ros_pkgs/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/ROSPlan/rosplan/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/ROSPlan/rosplan_rqt/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/sensors/stereo_camera_rig/rosserial/rosserial/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/sensors/stereo_camera_rig/rosserial/rosserial_arduino/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/sensors/stereo_camera_rig/rosserial/rosserial_mbed/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/sensors/stereo_camera_rig/rosserial/rosserial_msgs/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/sensors/stereo_camera_rig/rosserial/rosserial_python/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/sensors/stereo_camera_rig/rosserial/rosserial_tivac/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/sensors/stereo_camera_rig/rosserial/rosserial_vex_cortex/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/sensors/stereo_camera_rig/rosserial/rosserial_vex_v5/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/sensors/stereo_camera_rig/rosserial/rosserial_xbee/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/sensors/stereo_camera_rig/rosserial/rosserial_client/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/ROSPlan/rosplan_action_interface/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/sensors/stereo_camera_rig/exposure_controller/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/g2o_based_mapping/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/robot_control/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/robot_description/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/robot_gazebo/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/ROSPlan/rosplan_dispatch_msgs/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/ROSPlan/rosplan_knowledge_msgs/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/ROSPlan/rosplan_dependencies/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/ROSPlan/rosplan_sensing_interface/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/ROSPlan/rosplan_planning_system/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/sensors/stereo_camera_rig/rosserial/rosserial_server/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/gazebo_ros_pkgs/gazebo_msgs/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/sensors/stereo_camera_rig/image_timestamp_sync/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/robot_actions/robot_door_closing/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/robot_actions/robot_door_opening/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/gazebo_ros_pkgs/gazebo_ros/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/ROSPlan/rosplan_knowledge_base/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/sensors/stereo_camera_rig/rosserial/rosserial_embeddedlinux/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/sensors/stereo_camera_rig/rosserial/rosserial_test/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/sensors/stereo_camera_rig/rosserial/rosserial_windows/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/occupancy_grid_utils/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/laser_based_localization_pf/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/gazebo_ros_pkgs/gazebo_plugins/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/gazebo_ros_pkgs/gazebo_ros_control/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/lpn_global_path_planner/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/high_level_control/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/opt_local_planner/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/frontier_exploration/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/rrt_global_path_planner/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/sensors/sick_laser/sick_laser_description/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/sensors/stereo_camera_rig/stereo_camera_description/cmake_install.cmake")
  include("/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/sensors/zed_camera/zed_camera_description/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/thomas/Documents/university/ar/catkin_ws/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
