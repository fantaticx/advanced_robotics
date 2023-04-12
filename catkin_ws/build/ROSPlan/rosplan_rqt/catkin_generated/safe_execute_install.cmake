execute_process(COMMAND "/home/thomas/Documents/university/ar/catkin_ws/build/ROSPlan/rosplan_rqt/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/thomas/Documents/university/ar/catkin_ws/build/ROSPlan/rosplan_rqt/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
