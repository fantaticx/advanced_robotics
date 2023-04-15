;; Auto-generated. Do not edit!


(when (boundp 'rosplan_knowledge_msgs::GetInstanceService)
  (if (not (find-package "ROSPLAN_KNOWLEDGE_MSGS"))
    (make-package "ROSPLAN_KNOWLEDGE_MSGS"))
  (shadow 'GetInstanceService (find-package "ROSPLAN_KNOWLEDGE_MSGS")))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::GETINSTANCESERVICE")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::GETINSTANCESERVICE"))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::GETINSTANCESERVICEREQUEST")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::GETINSTANCESERVICEREQUEST"))
(unless (find-package "ROSPLAN_KNOWLEDGE_MSGS::GETINSTANCESERVICERESPONSE")
  (make-package "ROSPLAN_KNOWLEDGE_MSGS::GETINSTANCESERVICERESPONSE"))

(in-package "ROS")





(defclass rosplan_knowledge_msgs::GetInstanceServiceRequest
  :super ros::object
  :slots (_type_name _include_constants _include_subtypes ))

(defmethod rosplan_knowledge_msgs::GetInstanceServiceRequest
  (:init
   (&key
    ((:type_name __type_name) "")
    ((:include_constants __include_constants) nil)
    ((:include_subtypes __include_subtypes) nil)
    )
   (send-super :init)
   (setq _type_name (string __type_name))
   (setq _include_constants __include_constants)
   (setq _include_subtypes __include_subtypes)
   self)
  (:type_name
   (&optional __type_name)
   (if __type_name (setq _type_name __type_name)) _type_name)
  (:include_constants
   (&optional (__include_constants :null))
   (if (not (eq __include_constants :null)) (setq _include_constants __include_constants)) _include_constants)
  (:include_subtypes
   (&optional (__include_subtypes :null))
   (if (not (eq __include_subtypes :null)) (setq _include_subtypes __include_subtypes)) _include_subtypes)
  (:serialization-length
   ()
   (+
    ;; string _type_name
    4 (length _type_name)
    ;; bool _include_constants
    1
    ;; bool _include_subtypes
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _type_name
       (write-long (length _type_name) s) (princ _type_name s)
     ;; bool _include_constants
       (if _include_constants (write-byte -1 s) (write-byte 0 s))
     ;; bool _include_subtypes
       (if _include_subtypes (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _type_name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _type_name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; bool _include_constants
     (setq _include_constants (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _include_subtypes
     (setq _include_subtypes (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass rosplan_knowledge_msgs::GetInstanceServiceResponse
  :super ros::object
  :slots (_instances ))

(defmethod rosplan_knowledge_msgs::GetInstanceServiceResponse
  (:init
   (&key
    ((:instances __instances) (let (r) (dotimes (i 0) (push "" r)) r))
    )
   (send-super :init)
   (setq _instances __instances)
   self)
  (:instances
   (&optional __instances)
   (if __instances (setq _instances __instances)) _instances)
  (:serialization-length
   ()
   (+
    ;; string[] _instances
    (apply #'+ (mapcar #'(lambda (x) (+ 4 (length x))) _instances)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string[] _instances
     (write-long (length _instances) s)
     (dolist (elem _instances)
       (write-long (length elem) s) (princ elem s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string[] _instances
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _instances (make-list n))
     (dotimes (i n)
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setf (elt _instances i) (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
     ))
   ;;
   self)
  )

(defclass rosplan_knowledge_msgs::GetInstanceService
  :super ros::object
  :slots ())

(setf (get rosplan_knowledge_msgs::GetInstanceService :md5sum-) "72fcbb7309926c5129a3fae2ecc031b8")
(setf (get rosplan_knowledge_msgs::GetInstanceService :datatype-) "rosplan_knowledge_msgs/GetInstanceService")
(setf (get rosplan_knowledge_msgs::GetInstanceService :request) rosplan_knowledge_msgs::GetInstanceServiceRequest)
(setf (get rosplan_knowledge_msgs::GetInstanceService :response) rosplan_knowledge_msgs::GetInstanceServiceResponse)

(defmethod rosplan_knowledge_msgs::GetInstanceServiceRequest
  (:response () (instance rosplan_knowledge_msgs::GetInstanceServiceResponse :init)))

(setf (get rosplan_knowledge_msgs::GetInstanceServiceRequest :md5sum-) "72fcbb7309926c5129a3fae2ecc031b8")
(setf (get rosplan_knowledge_msgs::GetInstanceServiceRequest :datatype-) "rosplan_knowledge_msgs/GetInstanceServiceRequest")
(setf (get rosplan_knowledge_msgs::GetInstanceServiceRequest :definition-)
      "# PDDL problem generation; service(1/3):
# Get all instances of the type with the name 'typeName'.
string type_name
bool include_constants
bool include_subtypes
---
string[] instances

")

(setf (get rosplan_knowledge_msgs::GetInstanceServiceResponse :md5sum-) "72fcbb7309926c5129a3fae2ecc031b8")
(setf (get rosplan_knowledge_msgs::GetInstanceServiceResponse :datatype-) "rosplan_knowledge_msgs/GetInstanceServiceResponse")
(setf (get rosplan_knowledge_msgs::GetInstanceServiceResponse :definition-)
      "# PDDL problem generation; service(1/3):
# Get all instances of the type with the name 'typeName'.
string type_name
bool include_constants
bool include_subtypes
---
string[] instances

")



(provide :rosplan_knowledge_msgs/GetInstanceService "72fcbb7309926c5129a3fae2ecc031b8")


