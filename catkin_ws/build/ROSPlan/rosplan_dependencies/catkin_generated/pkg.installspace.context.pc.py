# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include;/opt/ros/noetic/include;/opt/ros/noetic/share/xmlrpcpp/cmake/../../../include/xmlrpcpp;/usr/include".split(';') if "${prefix}/include;/opt/ros/noetic/include;/opt/ros/noetic/share/xmlrpcpp/cmake/../../../include/xmlrpcpp;/usr/include" != "" else []
PROJECT_CATKIN_DEPENDS = "roscpp;rosplan_knowledge_msgs".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lval_kcl;-lrddl_parser;-lippc_server;-lppddl_parser;-lhddl_parser".split(';') if "-lval_kcl;-lrddl_parser;-lippc_server;-lppddl_parser;-lhddl_parser" != "" else []
PROJECT_NAME = "rosplan_dependencies"
PROJECT_SPACE_DIR = "/home/thomas/Documents/university/ar/catkin_ws/install"
PROJECT_VERSION = "0.1.0"
