// Auto-generated. Do not edit!

// (in-package rosplan_knowledge_msgs.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class GetInstanceServiceRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.type_name = null;
      this.include_constants = null;
      this.include_subtypes = null;
    }
    else {
      if (initObj.hasOwnProperty('type_name')) {
        this.type_name = initObj.type_name
      }
      else {
        this.type_name = '';
      }
      if (initObj.hasOwnProperty('include_constants')) {
        this.include_constants = initObj.include_constants
      }
      else {
        this.include_constants = false;
      }
      if (initObj.hasOwnProperty('include_subtypes')) {
        this.include_subtypes = initObj.include_subtypes
      }
      else {
        this.include_subtypes = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GetInstanceServiceRequest
    // Serialize message field [type_name]
    bufferOffset = _serializer.string(obj.type_name, buffer, bufferOffset);
    // Serialize message field [include_constants]
    bufferOffset = _serializer.bool(obj.include_constants, buffer, bufferOffset);
    // Serialize message field [include_subtypes]
    bufferOffset = _serializer.bool(obj.include_subtypes, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GetInstanceServiceRequest
    let len;
    let data = new GetInstanceServiceRequest(null);
    // Deserialize message field [type_name]
    data.type_name = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [include_constants]
    data.include_constants = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [include_subtypes]
    data.include_subtypes = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.type_name);
    return length + 6;
  }

  static datatype() {
    // Returns string type for a service object
    return 'rosplan_knowledge_msgs/GetInstanceServiceRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b08994cebbc7393beeb400f9b26e7b16';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # PDDL problem generation; service(1/3):
    # Get all instances of the type with the name 'typeName'.
    string type_name
    bool include_constants
    bool include_subtypes
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new GetInstanceServiceRequest(null);
    if (msg.type_name !== undefined) {
      resolved.type_name = msg.type_name;
    }
    else {
      resolved.type_name = ''
    }

    if (msg.include_constants !== undefined) {
      resolved.include_constants = msg.include_constants;
    }
    else {
      resolved.include_constants = false
    }

    if (msg.include_subtypes !== undefined) {
      resolved.include_subtypes = msg.include_subtypes;
    }
    else {
      resolved.include_subtypes = false
    }

    return resolved;
    }
};

class GetInstanceServiceResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.instances = null;
    }
    else {
      if (initObj.hasOwnProperty('instances')) {
        this.instances = initObj.instances
      }
      else {
        this.instances = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GetInstanceServiceResponse
    // Serialize message field [instances]
    bufferOffset = _arraySerializer.string(obj.instances, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GetInstanceServiceResponse
    let len;
    let data = new GetInstanceServiceResponse(null);
    // Deserialize message field [instances]
    data.instances = _arrayDeserializer.string(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    object.instances.forEach((val) => {
      length += 4 + _getByteLength(val);
    });
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'rosplan_knowledge_msgs/GetInstanceServiceResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c37cf4d14d6c5bfa6fbe319c1865eb5a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string[] instances
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new GetInstanceServiceResponse(null);
    if (msg.instances !== undefined) {
      resolved.instances = msg.instances;
    }
    else {
      resolved.instances = []
    }

    return resolved;
    }
};

module.exports = {
  Request: GetInstanceServiceRequest,
  Response: GetInstanceServiceResponse,
  md5sum() { return '72fcbb7309926c5129a3fae2ecc031b8'; },
  datatype() { return 'rosplan_knowledge_msgs/GetInstanceService'; }
};
