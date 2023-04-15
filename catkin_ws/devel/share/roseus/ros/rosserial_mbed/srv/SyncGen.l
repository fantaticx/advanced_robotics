;; Auto-generated. Do not edit!


(when (boundp 'rosserial_mbed::SyncGen)
  (if (not (find-package "ROSSERIAL_MBED"))
    (make-package "ROSSERIAL_MBED"))
  (shadow 'SyncGen (find-package "ROSSERIAL_MBED")))
(unless (find-package "ROSSERIAL_MBED::SYNCGEN")
  (make-package "ROSSERIAL_MBED::SYNCGEN"))
(unless (find-package "ROSSERIAL_MBED::SYNCGENREQUEST")
  (make-package "ROSSERIAL_MBED::SYNCGENREQUEST"))
(unless (find-package "ROSSERIAL_MBED::SYNCGENRESPONSE")
  (make-package "ROSSERIAL_MBED::SYNCGENRESPONSE"))

(in-package "ROS")





(defclass rosserial_mbed::SyncGenRequest
  :super ros::object
  :slots (_frequency ))

(defmethod rosserial_mbed::SyncGenRequest
  (:init
   (&key
    ((:frequency __frequency) 0)
    )
   (send-super :init)
   (setq _frequency (round __frequency))
   self)
  (:frequency
   (&optional __frequency)
   (if __frequency (setq _frequency __frequency)) _frequency)
  (:serialization-length
   ()
   (+
    ;; int32 _frequency
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _frequency
       (write-long _frequency s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _frequency
     (setq _frequency (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass rosserial_mbed::SyncGenResponse
  :super ros::object
  :slots (_frequency ))

(defmethod rosserial_mbed::SyncGenResponse
  (:init
   (&key
    ((:frequency __frequency) 0)
    )
   (send-super :init)
   (setq _frequency (round __frequency))
   self)
  (:frequency
   (&optional __frequency)
   (if __frequency (setq _frequency __frequency)) _frequency)
  (:serialization-length
   ()
   (+
    ;; int32 _frequency
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _frequency
       (write-long _frequency s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _frequency
     (setq _frequency (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass rosserial_mbed::SyncGen
  :super ros::object
  :slots ())

(setf (get rosserial_mbed::SyncGen :md5sum-) "ea9d83d55be0e52c11fc70f07c9af7d8")
(setf (get rosserial_mbed::SyncGen :datatype-) "rosserial_mbed/SyncGen")
(setf (get rosserial_mbed::SyncGen :request) rosserial_mbed::SyncGenRequest)
(setf (get rosserial_mbed::SyncGen :response) rosserial_mbed::SyncGenResponse)

(defmethod rosserial_mbed::SyncGenRequest
  (:response () (instance rosserial_mbed::SyncGenResponse :init)))

(setf (get rosserial_mbed::SyncGenRequest :md5sum-) "ea9d83d55be0e52c11fc70f07c9af7d8")
(setf (get rosserial_mbed::SyncGenRequest :datatype-) "rosserial_mbed/SyncGenRequest")
(setf (get rosserial_mbed::SyncGenRequest :definition-)
      "int32 frequency
---
int32 frequency

")

(setf (get rosserial_mbed::SyncGenResponse :md5sum-) "ea9d83d55be0e52c11fc70f07c9af7d8")
(setf (get rosserial_mbed::SyncGenResponse :datatype-) "rosserial_mbed/SyncGenResponse")
(setf (get rosserial_mbed::SyncGenResponse :definition-)
      "int32 frequency
---
int32 frequency

")



(provide :rosserial_mbed/SyncGen "ea9d83d55be0e52c11fc70f07c9af7d8")


