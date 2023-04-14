# Install script for directory: /home/thomas/Documents/university/ar/catkin_ws/src/advanced_robotics_public/robot/robot_actions/robot_door_opening

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/robot_door_opening/action" TYPE FILE FILES "/home/thomas/Documents/university/ar/catkin_ws/src/advanced_robotics_public/robot/robot_actions/robot_door_opening/action/door_open.action")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/robot_door_opening/msg" TYPE FILE FILES
    "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_opening/msg/door_openAction.msg"
    "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_opening/msg/door_openActionGoal.msg"
    "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_opening/msg/door_openActionResult.msg"
    "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_opening/msg/door_openActionFeedback.msg"
    "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_opening/msg/door_openGoal.msg"
    "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_opening/msg/door_openResult.msg"
    "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_opening/msg/door_openFeedback.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/robot_door_opening/cmake" TYPE FILE FILES "/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/robot_actions/robot_door_opening/catkin_generated/installspace/robot_door_opening-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/thomas/Documents/university/ar/catkin_ws/devel/include/robot_door_opening")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/thomas/Documents/university/ar/catkin_ws/devel/share/roseus/ros/robot_door_opening")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/thomas/Documents/university/ar/catkin_ws/devel/share/common-lisp/ros/robot_door_opening")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/thomas/Documents/university/ar/catkin_ws/devel/share/gennodejs/ros/robot_door_opening")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python3" -m compileall "/home/thomas/Documents/university/ar/catkin_ws/devel/lib/python3/dist-packages/robot_door_opening")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3/dist-packages" TYPE DIRECTORY FILES "/home/thomas/Documents/university/ar/catkin_ws/devel/lib/python3/dist-packages/robot_door_opening")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/robot_actions/robot_door_opening/catkin_generated/installspace/robot_door_opening.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/robot_door_opening/cmake" TYPE FILE FILES "/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/robot_actions/robot_door_opening/catkin_generated/installspace/robot_door_opening-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/robot_door_opening/cmake" TYPE FILE FILES
    "/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/robot_actions/robot_door_opening/catkin_generated/installspace/robot_door_openingConfig.cmake"
    "/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/robot_actions/robot_door_opening/catkin_generated/installspace/robot_door_openingConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/robot_door_opening" TYPE FILE FILES "/home/thomas/Documents/university/ar/catkin_ws/src/advanced_robotics_public/robot/robot_actions/robot_door_opening/package.xml")
endif()

