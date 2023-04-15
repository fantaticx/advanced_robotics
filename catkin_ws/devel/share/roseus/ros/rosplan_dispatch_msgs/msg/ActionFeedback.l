;; Auto-generated. Do not edit!


(when (boundp 'rosplan_dispatch_msgs::ActionFeedback)
  (if (not (find-package "ROSPLAN_DISPATCH_MSGS"))
    (make-package "ROSPLAN_DISPATCH_MSGS"))
  (shadow 'ActionFeedback (find-package "ROSPLAN_DISPATCH_MSGS")))
(unless (find-package "ROSPLAN_DISPATCH_MSGS::ACTIONFEEDBACK")
  (make-package "ROSPLAN_DISPATCH_MSGS::ACTIONFEEDBACK"))

(in-package "ROS")
;;//! \htmlinclude ActionFeedback.msg.html
(if (not (find-package "DIAGNOSTIC_MSGS"))
  (ros::roseus-add-msgs "diagnostic_msgs"))


(intern "*ACTION_PRECONDITION_FALSE*" (find-package "ROSPLAN_DISPATCH_MSGS::ACTIONFEEDBACK"))
(shadow '*ACTION_PRECONDITION_FALSE* (find-package "ROSPLAN_DISPATCH_MSGS::ACTIONFEEDBACK"))
(defconstant rosplan_dispatch_msgs::ActionFeedback::*ACTION_PRECONDITION_FALSE* 0)
(intern "*ACTION_ENABLED*" (find-package "ROSPLAN_DISPATCH_MSGS::ACTIONFEEDBACK"))
(shadow '*ACTION_ENABLED* (find-package "ROSPLAN_DISPATCH_MSGS::ACTIONFEEDBACK"))
(defconstant rosplan_dispatch_msgs::ActionFeedback::*ACTION_ENABLED* 1)
(intern "*ACTION_DISPATCHED_TO_GOAL_STATE*" (find-package "ROSPLAN_DISPATCH_MSGS::ACTIONFEEDBACK"))
(shadow '*ACTION_DISPATCHED_TO_GOAL_STATE* (find-package "ROSPLAN_DISPATCH_MSGS::ACTIONFEEDBACK"))
(defconstant rosplan_dispatch_msgs::ActionFeedback::*ACTION_DISPATCHED_TO_GOAL_STATE* 1)
(intern "*ACTION_SUCCEEDED_TO_GOAL_STATE*" (find-package "ROSPLAN_DISPATCH_MSGS::ACTIONFEEDBACK"))
(shadow '*ACTION_SUCCEEDED_TO_GOAL_STATE* (find-package "ROSPLAN_DISPATCH_MSGS::ACTIONFEEDBACK"))
(defconstant rosplan_dispatch_msgs::ActionFeedback::*ACTION_SUCCEEDED_TO_GOAL_STATE* 2)
(intern "*ACTION_DISPATCHED_TO_START_STATE*" (find-package "ROSPLAN_DISPATCH_MSGS::ACTIONFEEDBACK"))
(shadow '*ACTION_DISPATCHED_TO_START_STATE* (find-package "ROSPLAN_DISPATCH_MSGS::ACTIONFEEDBACK"))
(defconstant rosplan_dispatch_msgs::ActionFeedback::*ACTION_DISPATCHED_TO_START_STATE* 3)
(intern "*ACTION_SUCCEEDED_TO_START_STATE*" (find-package "ROSPLAN_DISPATCH_MSGS::ACTIONFEEDBACK"))
(shadow '*ACTION_SUCCEEDED_TO_START_STATE* (find-package "ROSPLAN_DISPATCH_MSGS::ACTIONFEEDBACK"))
(defconstant rosplan_dispatch_msgs::ActionFeedback::*ACTION_SUCCEEDED_TO_START_STATE* 4)
(intern "*ACTION_FAILED*" (find-package "ROSPLAN_DISPATCH_MSGS::ACTIONFEEDBACK"))
(shadow '*ACTION_FAILED* (find-package "ROSPLAN_DISPATCH_MSGS::ACTIONFEEDBACK"))
(defconstant rosplan_dispatch_msgs::ActionFeedback::*ACTION_FAILED* 10)

(defun rosplan_dispatch_msgs::ActionFeedback-to-symbol (const)
  (cond
        ((= const 0) 'rosplan_dispatch_msgs::ActionFeedback::*ACTION_PRECONDITION_FALSE*)
        ((= const 1) 'rosplan_dispatch_msgs::ActionFeedback::*ACTION_ENABLED*)
        ((= const 1) 'rosplan_dispatch_msgs::ActionFeedback::*ACTION_DISPATCHED_TO_GOAL_STATE*)
        ((= const 2) 'rosplan_dispatch_msgs::ActionFeedback::*ACTION_SUCCEEDED_TO_GOAL_STATE*)
        ((= const 3) 'rosplan_dispatch_msgs::ActionFeedback::*ACTION_DISPATCHED_TO_START_STATE*)
        ((= const 4) 'rosplan_dispatch_msgs::ActionFeedback::*ACTION_SUCCEEDED_TO_START_STATE*)
        ((= const 10) 'rosplan_dispatch_msgs::ActionFeedback::*ACTION_FAILED*)
        (t nil)))

(defclass rosplan_dispatch_msgs::ActionFeedback
  :super ros::object
  :slots (_action_id _plan_id _status _information ))

(defmethod rosplan_dispatch_msgs::ActionFeedback
  (:init
   (&key
    ((:action_id __action_id) 0)
    ((:plan_id __plan_id) 0)
    ((:status __status) 0)
    ((:information __information) ())
    )
   (send-super :init)
   (setq _action_id (round __action_id))
   (setq _plan_id (round __plan_id))
   (setq _status (round __status))
   (setq _information __information)
   self)
  (:action_id
   (&optional __action_id)
   (if __action_id (setq _action_id __action_id)) _action_id)
  (:plan_id
   (&optional __plan_id)
   (if __plan_id (setq _plan_id __plan_id)) _plan_id)
  (:status
   (&optional __status)
   (if __status (setq _status __status)) _status)
  (:information
   (&rest __information)
   (if (keywordp (car __information))
       (send* _information __information)
     (progn
       (if __information (setq _information (car __information)))
       _information)))
  (:serialization-length
   ()
   (+
    ;; int32 _action_id
    4
    ;; int32 _plan_id
    4
    ;; int32 _status
    4
    ;; diagnostic_msgs/KeyValue[] _information
    (apply #'+ (send-all _information :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _action_id
       (write-long _action_id s)
     ;; int32 _plan_id
       (write-long _plan_id s)
     ;; int32 _status
       (write-long _status s)
     ;; diagnostic_msgs/KeyValue[] _information
     (write-long (length _information) s)
     (dolist (elem _information)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _action_id
     (setq _action_id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _plan_id
     (setq _plan_id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _status
     (setq _status (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; diagnostic_msgs/KeyValue[] _information
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _information (let (r) (dotimes (i n) (push (instance diagnostic_msgs::KeyValue :init) r)) r))
     (dolist (elem- _information)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get rosplan_dispatch_msgs::ActionFeedback :md5sum-) "6efa68a42d1d10ddf52cc6b649317f64")
(setf (get rosplan_dispatch_msgs::ActionFeedback :datatype-) "rosplan_dispatch_msgs/ActionFeedback")
(setf (get rosplan_dispatch_msgs::ActionFeedback :definition-)
      "#actionFeedback message
int32 ACTION_PRECONDITION_FALSE = 0
int32 ACTION_ENABLED = 1
int32 ACTION_DISPATCHED_TO_GOAL_STATE = 1
int32 ACTION_SUCCEEDED_TO_GOAL_STATE = 2
int32 ACTION_DISPATCHED_TO_START_STATE = 3
int32 ACTION_SUCCEEDED_TO_START_STATE = 4
int32 ACTION_FAILED = 10

int32 action_id
int32 plan_id
int32 status
diagnostic_msgs/KeyValue[] information

================================================================================
MSG: diagnostic_msgs/KeyValue
string key # what to label this value when viewing
string value # a value to track over time

")



(provide :rosplan_dispatch_msgs/ActionFeedback "6efa68a42d1d10ddf52cc6b649317f64")


