# Install script for directory: /home/thomas/Documents/university/ar/catkin_ws/src/advanced_robotics_public/robot/robot_actions/robot_door_closing

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
    set(CMAKE_INSTALL_CONFIG_NAME "")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/robot_door_closing/action" TYPE FILE FILES "/home/thomas/Documents/university/ar/catkin_ws/src/advanced_robotics_public/robot/robot_actions/robot_door_closing/action/door_close.action")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/robot_door_closing/msg" TYPE FILE FILES
    "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeAction.msg"
    "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionGoal.msg"
    "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionResult.msg"
    "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionFeedback.msg"
    "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeGoal.msg"
    "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeResult.msg"
    "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeFeedback.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/robot_door_closing/cmake" TYPE FILE FILES "/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/robot_actions/robot_door_closing/catkin_generated/installspace/robot_door_closing-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/thomas/Documents/university/ar/catkin_ws/devel/include/robot_door_closing")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/thomas/Documents/university/ar/catkin_ws/devel/share/roseus/ros/robot_door_closing")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/thomas/Documents/university/ar/catkin_ws/devel/share/common-lisp/ros/robot_door_closing")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/thomas/Documents/university/ar/catkin_ws/devel/share/gennodejs/ros/robot_door_closing")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python3" -m compileall "/home/thomas/Documents/university/ar/catkin_ws/devel/lib/python3/dist-packages/robot_door_closing")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3/dist-packages" TYPE DIRECTORY FILES "/home/thomas/Documents/university/ar/catkin_ws/devel/lib/python3/dist-packages/robot_door_closing")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/robot_actions/robot_door_closing/catkin_generated/installspace/robot_door_closing.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/robot_door_closing/cmake" TYPE FILE FILES "/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/robot_actions/robot_door_closing/catkin_generated/installspace/robot_door_closing-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/robot_door_closing/cmake" TYPE FILE FILES
    "/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/robot_actions/robot_door_closing/catkin_generated/installspace/robot_door_closingConfig.cmake"
    "/home/thomas/Documents/university/ar/catkin_ws/build/advanced_robotics_public/robot/robot_actions/robot_door_closing/catkin_generated/installspace/robot_door_closingConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/robot_door_closing" TYPE FILE FILES "/home/thomas/Documents/university/ar/catkin_ws/src/advanced_robotics_public/robot/robot_actions/robot_door_closing/package.xml")
endif()

