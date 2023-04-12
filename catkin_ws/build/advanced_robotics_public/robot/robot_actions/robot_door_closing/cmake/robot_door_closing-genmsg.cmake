# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "robot_door_closing: 7 messages, 0 services")

set(MSG_I_FLAGS "-Irobot_door_closing:/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg;-Iactionlib_msgs:/opt/ros/noetic/share/actionlib_msgs/cmake/../msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(robot_door_closing_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeAction.msg" NAME_WE)
add_custom_target(_robot_door_closing_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "robot_door_closing" "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeAction.msg" "robot_door_closing/door_closeGoal:actionlib_msgs/GoalStatus:std_msgs/Header:robot_door_closing/door_closeResult:robot_door_closing/door_closeFeedback:actionlib_msgs/GoalID:robot_door_closing/door_closeActionResult:robot_door_closing/door_closeActionFeedback:robot_door_closing/door_closeActionGoal"
)

get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionGoal.msg" NAME_WE)
add_custom_target(_robot_door_closing_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "robot_door_closing" "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionGoal.msg" "robot_door_closing/door_closeGoal:std_msgs/Header:actionlib_msgs/GoalID"
)

get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionResult.msg" NAME_WE)
add_custom_target(_robot_door_closing_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "robot_door_closing" "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionResult.msg" "actionlib_msgs/GoalStatus:robot_door_closing/door_closeResult:std_msgs/Header:actionlib_msgs/GoalID"
)

get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionFeedback.msg" NAME_WE)
add_custom_target(_robot_door_closing_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "robot_door_closing" "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionFeedback.msg" "actionlib_msgs/GoalStatus:std_msgs/Header:robot_door_closing/door_closeFeedback:actionlib_msgs/GoalID"
)

get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeGoal.msg" NAME_WE)
add_custom_target(_robot_door_closing_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "robot_door_closing" "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeGoal.msg" ""
)

get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeResult.msg" NAME_WE)
add_custom_target(_robot_door_closing_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "robot_door_closing" "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeResult.msg" ""
)

get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeFeedback.msg" NAME_WE)
add_custom_target(_robot_door_closing_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "robot_door_closing" "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeFeedback.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeAction.msg"
  "${MSG_I_FLAGS}"
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeGoal.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeResult.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeFeedback.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionResult.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionFeedback.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robot_door_closing
)
_generate_msg_cpp(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeGoal.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robot_door_closing
)
_generate_msg_cpp(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeResult.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robot_door_closing
)
_generate_msg_cpp(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeFeedback.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robot_door_closing
)
_generate_msg_cpp(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robot_door_closing
)
_generate_msg_cpp(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robot_door_closing
)
_generate_msg_cpp(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robot_door_closing
)

### Generating Services

### Generating Module File
_generate_module_cpp(robot_door_closing
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robot_door_closing
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(robot_door_closing_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(robot_door_closing_generate_messages robot_door_closing_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeAction.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_cpp _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionGoal.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_cpp _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionResult.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_cpp _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionFeedback.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_cpp _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeGoal.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_cpp _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeResult.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_cpp _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeFeedback.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_cpp _robot_door_closing_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(robot_door_closing_gencpp)
add_dependencies(robot_door_closing_gencpp robot_door_closing_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS robot_door_closing_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeAction.msg"
  "${MSG_I_FLAGS}"
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeGoal.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeResult.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeFeedback.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionResult.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionFeedback.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robot_door_closing
)
_generate_msg_eus(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeGoal.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robot_door_closing
)
_generate_msg_eus(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeResult.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robot_door_closing
)
_generate_msg_eus(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeFeedback.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robot_door_closing
)
_generate_msg_eus(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robot_door_closing
)
_generate_msg_eus(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robot_door_closing
)
_generate_msg_eus(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robot_door_closing
)

### Generating Services

### Generating Module File
_generate_module_eus(robot_door_closing
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robot_door_closing
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(robot_door_closing_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(robot_door_closing_generate_messages robot_door_closing_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeAction.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_eus _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionGoal.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_eus _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionResult.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_eus _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionFeedback.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_eus _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeGoal.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_eus _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeResult.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_eus _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeFeedback.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_eus _robot_door_closing_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(robot_door_closing_geneus)
add_dependencies(robot_door_closing_geneus robot_door_closing_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS robot_door_closing_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeAction.msg"
  "${MSG_I_FLAGS}"
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeGoal.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeResult.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeFeedback.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionResult.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionFeedback.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robot_door_closing
)
_generate_msg_lisp(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeGoal.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robot_door_closing
)
_generate_msg_lisp(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeResult.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robot_door_closing
)
_generate_msg_lisp(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeFeedback.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robot_door_closing
)
_generate_msg_lisp(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robot_door_closing
)
_generate_msg_lisp(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robot_door_closing
)
_generate_msg_lisp(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robot_door_closing
)

### Generating Services

### Generating Module File
_generate_module_lisp(robot_door_closing
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robot_door_closing
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(robot_door_closing_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(robot_door_closing_generate_messages robot_door_closing_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeAction.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_lisp _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionGoal.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_lisp _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionResult.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_lisp _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionFeedback.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_lisp _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeGoal.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_lisp _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeResult.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_lisp _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeFeedback.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_lisp _robot_door_closing_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(robot_door_closing_genlisp)
add_dependencies(robot_door_closing_genlisp robot_door_closing_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS robot_door_closing_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeAction.msg"
  "${MSG_I_FLAGS}"
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeGoal.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeResult.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeFeedback.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionResult.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionFeedback.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robot_door_closing
)
_generate_msg_nodejs(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeGoal.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robot_door_closing
)
_generate_msg_nodejs(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeResult.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robot_door_closing
)
_generate_msg_nodejs(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeFeedback.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robot_door_closing
)
_generate_msg_nodejs(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robot_door_closing
)
_generate_msg_nodejs(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robot_door_closing
)
_generate_msg_nodejs(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robot_door_closing
)

### Generating Services

### Generating Module File
_generate_module_nodejs(robot_door_closing
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robot_door_closing
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(robot_door_closing_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(robot_door_closing_generate_messages robot_door_closing_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeAction.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_nodejs _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionGoal.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_nodejs _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionResult.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_nodejs _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionFeedback.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_nodejs _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeGoal.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_nodejs _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeResult.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_nodejs _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeFeedback.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_nodejs _robot_door_closing_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(robot_door_closing_gennodejs)
add_dependencies(robot_door_closing_gennodejs robot_door_closing_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS robot_door_closing_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeAction.msg"
  "${MSG_I_FLAGS}"
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeGoal.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeResult.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeFeedback.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionResult.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionFeedback.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robot_door_closing
)
_generate_msg_py(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeGoal.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robot_door_closing
)
_generate_msg_py(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeResult.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robot_door_closing
)
_generate_msg_py(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeFeedback.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robot_door_closing
)
_generate_msg_py(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robot_door_closing
)
_generate_msg_py(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robot_door_closing
)
_generate_msg_py(robot_door_closing
  "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robot_door_closing
)

### Generating Services

### Generating Module File
_generate_module_py(robot_door_closing
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robot_door_closing
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(robot_door_closing_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(robot_door_closing_generate_messages robot_door_closing_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeAction.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_py _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionGoal.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_py _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionResult.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_py _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeActionFeedback.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_py _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeGoal.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_py _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeResult.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_py _robot_door_closing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/thomas/Documents/university/ar/catkin_ws/devel/share/robot_door_closing/msg/door_closeFeedback.msg" NAME_WE)
add_dependencies(robot_door_closing_generate_messages_py _robot_door_closing_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(robot_door_closing_genpy)
add_dependencies(robot_door_closing_genpy robot_door_closing_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS robot_door_closing_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robot_door_closing)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robot_door_closing
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_cpp)
  add_dependencies(robot_door_closing_generate_messages_cpp actionlib_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(robot_door_closing_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robot_door_closing)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robot_door_closing
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_eus)
  add_dependencies(robot_door_closing_generate_messages_eus actionlib_msgs_generate_messages_eus)
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(robot_door_closing_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robot_door_closing)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robot_door_closing
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_lisp)
  add_dependencies(robot_door_closing_generate_messages_lisp actionlib_msgs_generate_messages_lisp)
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(robot_door_closing_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robot_door_closing)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robot_door_closing
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_nodejs)
  add_dependencies(robot_door_closing_generate_messages_nodejs actionlib_msgs_generate_messages_nodejs)
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(robot_door_closing_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robot_door_closing)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robot_door_closing\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robot_door_closing
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_py)
  add_dependencies(robot_door_closing_generate_messages_py actionlib_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(robot_door_closing_generate_messages_py std_msgs_generate_messages_py)
endif()
