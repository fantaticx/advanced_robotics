
(cl:in-package :asdf)

(defsystem "robot_door_opening-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :actionlib_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "door_openAction" :depends-on ("_package_door_openAction"))
    (:file "_package_door_openAction" :depends-on ("_package"))
    (:file "door_openActionFeedback" :depends-on ("_package_door_openActionFeedback"))
    (:file "_package_door_openActionFeedback" :depends-on ("_package"))
    (:file "door_openActionGoal" :depends-on ("_package_door_openActionGoal"))
    (:file "_package_door_openActionGoal" :depends-on ("_package"))
    (:file "door_openActionResult" :depends-on ("_package_door_openActionResult"))
    (:file "_package_door_openActionResult" :depends-on ("_package"))
    (:file "door_openFeedback" :depends-on ("_package_door_openFeedback"))
    (:file "_package_door_openFeedback" :depends-on ("_package"))
    (:file "door_openGoal" :depends-on ("_package_door_openGoal"))
    (:file "_package_door_openGoal" :depends-on ("_package"))
    (:file "door_openResult" :depends-on ("_package_door_openResult"))
    (:file "_package_door_openResult" :depends-on ("_package"))
  ))