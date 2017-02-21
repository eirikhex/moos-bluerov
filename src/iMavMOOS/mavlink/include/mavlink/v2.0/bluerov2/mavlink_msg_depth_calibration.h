#pragma once
// MESSAGE DEPTH_CALIBRATION PACKING

#define MAVLINK_MSG_ID_DEPTH_CALIBRATION 228

MAVPACKED(
typedef struct __mavlink_depth_calibration_t {
 float cal_depth; /*< Calibrate sensor by using a known depth*/
 float cal_pressure; /*< Calibrate sensor by using known surface pressure*/
 float water_density; /*< Specific density of water used in depth calculation*/
}) mavlink_depth_calibration_t;

#define MAVLINK_MSG_ID_DEPTH_CALIBRATION_LEN 12
#define MAVLINK_MSG_ID_DEPTH_CALIBRATION_MIN_LEN 12
#define MAVLINK_MSG_ID_228_LEN 12
#define MAVLINK_MSG_ID_228_MIN_LEN 12

#define MAVLINK_MSG_ID_DEPTH_CALIBRATION_CRC 143
#define MAVLINK_MSG_ID_228_CRC 143



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DEPTH_CALIBRATION { \
    228, \
    "DEPTH_CALIBRATION", \
    3, \
    {  { "cal_depth", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_depth_calibration_t, cal_depth) }, \
         { "cal_pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_depth_calibration_t, cal_pressure) }, \
         { "water_density", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_depth_calibration_t, water_density) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DEPTH_CALIBRATION { \
    "DEPTH_CALIBRATION", \
    3, \
    {  { "cal_depth", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_depth_calibration_t, cal_depth) }, \
         { "cal_pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_depth_calibration_t, cal_pressure) }, \
         { "water_density", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_depth_calibration_t, water_density) }, \
         } \
}
#endif

/**
 * @brief Pack a depth_calibration message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param cal_depth Calibrate sensor by using a known depth
 * @param cal_pressure Calibrate sensor by using known surface pressure
 * @param water_density Specific density of water used in depth calculation
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_depth_calibration_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float cal_depth, float cal_pressure, float water_density)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DEPTH_CALIBRATION_LEN];
    _mav_put_float(buf, 0, cal_depth);
    _mav_put_float(buf, 4, cal_pressure);
    _mav_put_float(buf, 8, water_density);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DEPTH_CALIBRATION_LEN);
#else
    mavlink_depth_calibration_t packet;
    packet.cal_depth = cal_depth;
    packet.cal_pressure = cal_pressure;
    packet.water_density = water_density;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DEPTH_CALIBRATION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DEPTH_CALIBRATION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DEPTH_CALIBRATION_MIN_LEN, MAVLINK_MSG_ID_DEPTH_CALIBRATION_LEN, MAVLINK_MSG_ID_DEPTH_CALIBRATION_CRC);
}

/**
 * @brief Pack a depth_calibration message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cal_depth Calibrate sensor by using a known depth
 * @param cal_pressure Calibrate sensor by using known surface pressure
 * @param water_density Specific density of water used in depth calculation
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_depth_calibration_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float cal_depth,float cal_pressure,float water_density)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DEPTH_CALIBRATION_LEN];
    _mav_put_float(buf, 0, cal_depth);
    _mav_put_float(buf, 4, cal_pressure);
    _mav_put_float(buf, 8, water_density);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DEPTH_CALIBRATION_LEN);
#else
    mavlink_depth_calibration_t packet;
    packet.cal_depth = cal_depth;
    packet.cal_pressure = cal_pressure;
    packet.water_density = water_density;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DEPTH_CALIBRATION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DEPTH_CALIBRATION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DEPTH_CALIBRATION_MIN_LEN, MAVLINK_MSG_ID_DEPTH_CALIBRATION_LEN, MAVLINK_MSG_ID_DEPTH_CALIBRATION_CRC);
}

/**
 * @brief Encode a depth_calibration struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param depth_calibration C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_depth_calibration_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_depth_calibration_t* depth_calibration)
{
    return mavlink_msg_depth_calibration_pack(system_id, component_id, msg, depth_calibration->cal_depth, depth_calibration->cal_pressure, depth_calibration->water_density);
}

/**
 * @brief Encode a depth_calibration struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param depth_calibration C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_depth_calibration_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_depth_calibration_t* depth_calibration)
{
    return mavlink_msg_depth_calibration_pack_chan(system_id, component_id, chan, msg, depth_calibration->cal_depth, depth_calibration->cal_pressure, depth_calibration->water_density);
}

/**
 * @brief Send a depth_calibration message
 * @param chan MAVLink channel to send the message
 *
 * @param cal_depth Calibrate sensor by using a known depth
 * @param cal_pressure Calibrate sensor by using known surface pressure
 * @param water_density Specific density of water used in depth calculation
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_depth_calibration_send(mavlink_channel_t chan, float cal_depth, float cal_pressure, float water_density)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DEPTH_CALIBRATION_LEN];
    _mav_put_float(buf, 0, cal_depth);
    _mav_put_float(buf, 4, cal_pressure);
    _mav_put_float(buf, 8, water_density);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DEPTH_CALIBRATION, buf, MAVLINK_MSG_ID_DEPTH_CALIBRATION_MIN_LEN, MAVLINK_MSG_ID_DEPTH_CALIBRATION_LEN, MAVLINK_MSG_ID_DEPTH_CALIBRATION_CRC);
#else
    mavlink_depth_calibration_t packet;
    packet.cal_depth = cal_depth;
    packet.cal_pressure = cal_pressure;
    packet.water_density = water_density;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DEPTH_CALIBRATION, (const char *)&packet, MAVLINK_MSG_ID_DEPTH_CALIBRATION_MIN_LEN, MAVLINK_MSG_ID_DEPTH_CALIBRATION_LEN, MAVLINK_MSG_ID_DEPTH_CALIBRATION_CRC);
#endif
}

/**
 * @brief Send a depth_calibration message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_depth_calibration_send_struct(mavlink_channel_t chan, const mavlink_depth_calibration_t* depth_calibration)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_depth_calibration_send(chan, depth_calibration->cal_depth, depth_calibration->cal_pressure, depth_calibration->water_density);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DEPTH_CALIBRATION, (const char *)depth_calibration, MAVLINK_MSG_ID_DEPTH_CALIBRATION_MIN_LEN, MAVLINK_MSG_ID_DEPTH_CALIBRATION_LEN, MAVLINK_MSG_ID_DEPTH_CALIBRATION_CRC);
#endif
}

#if MAVLINK_MSG_ID_DEPTH_CALIBRATION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_depth_calibration_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float cal_depth, float cal_pressure, float water_density)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, cal_depth);
    _mav_put_float(buf, 4, cal_pressure);
    _mav_put_float(buf, 8, water_density);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DEPTH_CALIBRATION, buf, MAVLINK_MSG_ID_DEPTH_CALIBRATION_MIN_LEN, MAVLINK_MSG_ID_DEPTH_CALIBRATION_LEN, MAVLINK_MSG_ID_DEPTH_CALIBRATION_CRC);
#else
    mavlink_depth_calibration_t *packet = (mavlink_depth_calibration_t *)msgbuf;
    packet->cal_depth = cal_depth;
    packet->cal_pressure = cal_pressure;
    packet->water_density = water_density;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DEPTH_CALIBRATION, (const char *)packet, MAVLINK_MSG_ID_DEPTH_CALIBRATION_MIN_LEN, MAVLINK_MSG_ID_DEPTH_CALIBRATION_LEN, MAVLINK_MSG_ID_DEPTH_CALIBRATION_CRC);
#endif
}
#endif

#endif

// MESSAGE DEPTH_CALIBRATION UNPACKING


/**
 * @brief Get field cal_depth from depth_calibration message
 *
 * @return Calibrate sensor by using a known depth
 */
static inline float mavlink_msg_depth_calibration_get_cal_depth(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field cal_pressure from depth_calibration message
 *
 * @return Calibrate sensor by using known surface pressure
 */
static inline float mavlink_msg_depth_calibration_get_cal_pressure(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field water_density from depth_calibration message
 *
 * @return Specific density of water used in depth calculation
 */
static inline float mavlink_msg_depth_calibration_get_water_density(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Decode a depth_calibration message into a struct
 *
 * @param msg The message to decode
 * @param depth_calibration C-struct to decode the message contents into
 */
static inline void mavlink_msg_depth_calibration_decode(const mavlink_message_t* msg, mavlink_depth_calibration_t* depth_calibration)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    depth_calibration->cal_depth = mavlink_msg_depth_calibration_get_cal_depth(msg);
    depth_calibration->cal_pressure = mavlink_msg_depth_calibration_get_cal_pressure(msg);
    depth_calibration->water_density = mavlink_msg_depth_calibration_get_water_density(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DEPTH_CALIBRATION_LEN? msg->len : MAVLINK_MSG_ID_DEPTH_CALIBRATION_LEN;
        memset(depth_calibration, 0, MAVLINK_MSG_ID_DEPTH_CALIBRATION_LEN);
    memcpy(depth_calibration, _MAV_PAYLOAD(msg), len);
#endif
}
