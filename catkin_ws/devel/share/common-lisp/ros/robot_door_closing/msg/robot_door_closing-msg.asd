
(cl:in-package :asdf)

(defsystem "robot_door_closing-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :actionlib_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "door_closeAction" :depends-on ("_package_door_closeAction"))
    (:file "_package_door_closeAction" :depends-on ("_package"))
    (:file "door_closeActionFeedback" :depends-on ("_package_door_closeActionFeedback"))
    (:file "_package_door_closeActionFeedback" :depends-on ("_package"))
    (:file "door_closeActionGoal" :depends-on ("_package_door_closeActionGoal"))
    (:file "_package_door_closeActionGoal" :depends-on ("_package"))
    (:file "door_closeActionResult" :depends-on ("_package_door_closeActionResult"))
    (:file "_package_door_closeActionResult" :depends-on ("_package"))
    (:file "door_closeFeedback" :depends-on ("_package_door_closeFeedback"))
    (:file "_package_door_closeFeedback" :depends-on ("_package"))
    (:file "door_closeGoal" :depends-on ("_package_door_closeGoal"))
    (:file "_package_door_closeGoal" :depends-on ("_package"))
    (:file "door_closeResult" :depends-on ("_package_door_closeResult"))
    (:file "_package_door_closeResult" :depends-on ("_package"))
  ))