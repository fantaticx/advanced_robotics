; Auto-generated. Do not edit!


(cl:in-package rosserial_mbed-srv)


;//! \htmlinclude SyncGen-request.msg.html

(cl:defclass <SyncGen-request> (roslisp-msg-protocol:ros-message)
  ((frequency
    :reader frequency
    :initarg :frequency
    :type cl:integer
    :initform 0))
)

(cl:defclass SyncGen-request (<SyncGen-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SyncGen-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SyncGen-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosserial_mbed-srv:<SyncGen-request> is deprecated: use rosserial_mbed-srv:SyncGen-request instead.")))

(cl:ensure-generic-function 'frequency-val :lambda-list '(m))
(cl:defmethod frequency-val ((m <SyncGen-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosserial_mbed-srv:frequency-val is deprecated.  Use rosserial_mbed-srv:frequency instead.")
  (frequency m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SyncGen-request>) ostream)
  "Serializes a message object of type '<SyncGen-request>"
  (cl:let* ((signed (cl:slot-value msg 'frequency)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SyncGen-request>) istream)
  "Deserializes a message object of type '<SyncGen-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'frequency) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SyncGen-request>)))
  "Returns string type for a service object of type '<SyncGen-request>"
  "rosserial_mbed/SyncGenRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SyncGen-request)))
  "Returns string type for a service object of type 'SyncGen-request"
  "rosserial_mbed/SyncGenRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SyncGen-request>)))
  "Returns md5sum for a message object of type '<SyncGen-request>"
  "ea9d83d55be0e52c11fc70f07c9af7d8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SyncGen-request)))
  "Returns md5sum for a message object of type 'SyncGen-request"
  "ea9d83d55be0e52c11fc70f07c9af7d8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SyncGen-request>)))
  "Returns full string definition for message of type '<SyncGen-request>"
  (cl:format cl:nil "int32 frequency~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SyncGen-request)))
  "Returns full string definition for message of type 'SyncGen-request"
  (cl:format cl:nil "int32 frequency~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SyncGen-request>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SyncGen-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SyncGen-request
    (cl:cons ':frequency (frequency msg))
))
;//! \htmlinclude SyncGen-response.msg.html

(cl:defclass <SyncGen-response> (roslisp-msg-protocol:ros-message)
  ((frequency
    :reader frequency
    :initarg :frequency
    :type cl:integer
    :initform 0))
)

(cl:defclass SyncGen-response (<SyncGen-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SyncGen-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SyncGen-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosserial_mbed-srv:<SyncGen-response> is deprecated: use rosserial_mbed-srv:SyncGen-response instead.")))

(cl:ensure-generic-function 'frequency-val :lambda-list '(m))
(cl:defmethod frequency-val ((m <SyncGen-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosserial_mbed-srv:frequency-val is deprecated.  Use rosserial_mbed-srv:frequency instead.")
  (frequency m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SyncGen-response>) ostream)
  "Serializes a message object of type '<SyncGen-response>"
  (cl:let* ((signed (cl:slot-value msg 'frequency)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SyncGen-response>) istream)
  "Deserializes a message object of type '<SyncGen-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'frequency) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SyncGen-response>)))
  "Returns string type for a service object of type '<SyncGen-response>"
  "rosserial_mbed/SyncGenResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SyncGen-response)))
  "Returns string type for a service object of type 'SyncGen-response"
  "rosserial_mbed/SyncGenResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SyncGen-response>)))
  "Returns md5sum for a message object of type '<SyncGen-response>"
  "ea9d83d55be0e52c11fc70f07c9af7d8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SyncGen-response)))
  "Returns md5sum for a message object of type 'SyncGen-response"
  "ea9d83d55be0e52c11fc70f07c9af7d8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SyncGen-response>)))
  "Returns full string definition for message of type '<SyncGen-response>"
  (cl:format cl:nil "int32 frequency~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SyncGen-response)))
  "Returns full string definition for message of type 'SyncGen-response"
  (cl:format cl:nil "int32 frequency~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SyncGen-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SyncGen-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SyncGen-response
    (cl:cons ':frequency (frequency msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SyncGen)))
  'SyncGen-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SyncGen)))
  'SyncGen-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SyncGen)))
  "Returns string type for a service object of type '<SyncGen>"
  "rosserial_mbed/SyncGen")