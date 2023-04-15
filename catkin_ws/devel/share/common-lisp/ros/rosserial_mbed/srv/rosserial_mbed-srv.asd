
(cl:in-package :asdf)

(defsystem "rosserial_mbed-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "SyncGen" :depends-on ("_package_SyncGen"))
    (:file "_package_SyncGen" :depends-on ("_package"))
    (:file "Test" :depends-on ("_package_Test"))
    (:file "_package_Test" :depends-on ("_package"))
  ))