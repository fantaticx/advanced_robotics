// Auto-generated. Do not edit!

// (in-package rosserial_mbed.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class SyncGenRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.frequency = null;
    }
    else {
      if (initObj.hasOwnProperty('frequency')) {
        this.frequency = initObj.frequency
      }
      else {
        this.frequency = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SyncGenRequest
    // Serialize message field [frequency]
    bufferOffset = _serializer.int32(obj.frequency, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SyncGenRequest
    let len;
    let data = new SyncGenRequest(null);
    // Deserialize message field [frequency]
    data.frequency = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'rosserial_mbed/SyncGenRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '28a032761c91475f369a1e6b6a4c8553';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 frequency
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SyncGenRequest(null);
    if (msg.frequency !== undefined) {
      resolved.frequency = msg.frequency;
    }
    else {
      resolved.frequency = 0
    }

    return resolved;
    }
};

class SyncGenResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.frequency = null;
    }
    else {
      if (initObj.hasOwnProperty('frequency')) {
        this.frequency = initObj.frequency
      }
      else {
        this.frequency = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SyncGenResponse
    // Serialize message field [frequency]
    bufferOffset = _serializer.int32(obj.frequency, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SyncGenResponse
    let len;
    let data = new SyncGenResponse(null);
    // Deserialize message field [frequency]
    data.frequency = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'rosserial_mbed/SyncGenResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '28a032761c91475f369a1e6b6a4c8553';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 frequency
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SyncGenResponse(null);
    if (msg.frequency !== undefined) {
      resolved.frequency = msg.frequency;
    }
    else {
      resolved.frequency = 0
    }

    return resolved;
    }
};

module.exports = {
  Request: SyncGenRequest,
  Response: SyncGenResponse,
  md5sum() { return 'ea9d83d55be0e52c11fc70f07c9af7d8'; },
  datatype() { return 'rosserial_mbed/SyncGen'; }
};
