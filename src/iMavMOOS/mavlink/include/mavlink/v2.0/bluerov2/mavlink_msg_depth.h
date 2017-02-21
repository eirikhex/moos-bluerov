#pragma once
// MESSAGE DEPTH PACKING

#define MAVLINK_MSG_ID_DEPTH 227

MAVPACKED(
typedef struct __mavlink_depth_t {
 float abs_pressure; /*< Absolute measured pressure*/
 float temperature; /*< Measured temperature*/
 float diff_pressure; /*< Calculated Differential pressure*/
 float cal_pressure; /*< Calibrated pressure at surface*/
 float depth; /*< Calculated depth*/
 float water_density; /*< Specific density of water used in depth calculation*/
}) mavlink_depth_t;

#define MAVLINK_MSG_ID_DEPTH_LEN 24
#define MAVLINK_MSG_ID_DEPTH_MIN_LEN 24
#define MAVLINK_MSG_ID_227_LEN 24
#define MAVLINK_MSG_ID_227_MIN_LEN 24

#define MAVLINK_MSG_ID_DEPTH_CRC 222
#define MAVLINK_MSG_ID_227_CRC 222



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DEPTH { \
    227, \
    "DEPTH", \
    6, \
    {  { "abs_pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_depth_t, abs_pressure) }, \
         { "temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_depth_t, temperature) }, \
         { "diff_pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_depth_t, diff_pressure) }, \
         { "cal_pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_depth_t, cal_pressure) }, \
         { "depth", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_depth_t, depth) }, \
         { "water_density", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_depth_t, water_density) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DEPTH { \
    "DEPTH", \
    6, \
    {  { "abs_pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_depth_t, abs_pressure) }, \
         { "temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_depth_t, temperature) }, \
         { "diff_pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_depth_t, diff_pressure) }, \
         { "cal_pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_depth_t, cal_pressure) }, \
         { "depth", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_depth_t, depth) }, \
         { "water_density", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_depth_t, water_density) }, \
         } \
}
#endif

/**
 * @brief Pack a depth message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param abs_pressure Absolute measured pressure
 * @param temperature Measured temperature
 * @param diff_pressure Calculated Differential pressure
 * @param cal_pressure Calibrated pressure at surface
 * @param depth Calculated depth
 * @param water_density Specific density of water used in depth calculation
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_depth_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float abs_pressure, float temperature, float diff_pressure, float cal_pressure, float depth, float water_density)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DEPTH_LEN];
    _mav_put_float(buf, 0, abs_pressure);
    _mav_put_float(buf, 4, temperature);
    _mav_put_float(buf, 8, diff_pressure);
    _mav_put_float(buf, 12, cal_pressure);
    _mav_put_float(buf, 16, depth);
    _mav_put_float(buf, 20, water_density);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DEPTH_LEN);
#else
    mavlink_depth_t packet;
    packet.abs_pressure = abs_pressure;
    packet.temperature = temperature;
    packet.diff_pressure = diff_pressure;
    packet.cal_pressure = cal_pressure;
    packet.depth = depth;
    packet.water_density = water_density;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DEPTH_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DEPTH;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DEPTH_MIN_LEN, MAVLINK_MSG_ID_DEPTH_LEN, MAVLINK_MSG_ID_DEPTH_CRC);
}

/**
 * @brief Pack a depth message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param abs_pressure Absolute measured pressure
 * @param temperature Measured temperature
 * @param diff_pressure Calculated Differential pressure
 * @param cal_pressure Calibrated pressure at surface
 * @param depth Calculated depth
 * @param water_density Specific density of water used in depth calculation
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_depth_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float abs_pressure,float temperature,float diff_pressure,float cal_pressure,float depth,float water_density)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DEPTH_LEN];
    _mav_put_float(buf, 0, abs_pressure);
    _mav_put_float(buf, 4, temperature);
    _mav_put_float(buf, 8, diff_pressure);
    _mav_put_float(buf, 12, cal_pressure);
    _mav_put_float(buf, 16, depth);
    _mav_put_float(buf, 20, water_density);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DEPTH_LEN);
#else
    mavlink_depth_t packet;
    packet.abs_pressure = abs_pressure;
    packet.temperature = temperature;
    packet.diff_pressure = diff_pressure;
    packet.cal_pressure = cal_pressure;
    packet.depth = depth;
    packet.water_density = water_density;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DEPTH_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DEPTH;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DEPTH_MIN_LEN, MAVLINK_MSG_ID_DEPTH_LEN, MAVLINK_MSG_ID_DEPTH_CRC);
}

/**
 * @brief Encode a depth struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param depth C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_depth_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_depth_t* depth)
{
    return mavlink_msg_depth_pack(system_id, component_id, msg, depth->abs_pressure, depth->temperature, depth->diff_pressure, depth->cal_pressure, depth->depth, depth->water_density);
}

/**
 * @brief Encode a depth struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param depth C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_depth_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_depth_t* depth)
{
    return mavlink_msg_depth_pack_chan(system_id, component_id, chan, msg, depth->abs_pressure, depth->temperature, depth->diff_pressure, depth->cal_pressure, depth->depth, depth->water_density);
}

/**
 * @brief Send a depth message
 * @param chan MAVLink channel to send the message
 *
 * @param abs_pressure Absolute measured pressure
 * @param temperature Measured temperature
 * @param diff_pressure Calculated Differential pressure
 * @param cal_pressure Calibrated pressure at surface
 * @param depth Calculated depth
 * @param water_density Specific density of water used in depth calculation
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_depth_send(mavlink_channel_t chan, float abs_pressure, float temperature, float diff_pressure, float cal_pressure, float depth, float water_density)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DEPTH_LEN];
    _mav_put_float(buf, 0, abs_pressure);
    _mav_put_float(buf, 4, temperature);
    _mav_put_float(buf, 8, diff_pressure);
    _mav_put_float(buf, 12, cal_pressure);
    _mav_put_float(buf, 16, depth);
    _mav_put_float(buf, 20, water_density);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DEPTH, buf, MAVLINK_MSG_ID_DEPTH_MIN_LEN, MAVLINK_MSG_ID_DEPTH_LEN, MAVLINK_MSG_ID_DEPTH_CRC);
#else
    mavlink_depth_t packet;
    packet.abs_pressure = abs_pressure;
    packet.temperature = temperature;
    packet.diff_pressure = diff_pressure;
    packet.cal_pressure = cal_pressure;
    packet.depth = depth;
    packet.water_density = water_density;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DEPTH, (const char *)&packet, MAVLINK_MSG_ID_DEPTH_MIN_LEN, MAVLINK_MSG_ID_DEPTH_LEN, MAVLINK_MSG_ID_DEPTH_CRC);
#endif
}

/**
 * @brief Send a depth message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_depth_send_struct(mavlink_channel_t chan, const mavlink_depth_t* depth)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_depth_send(chan, depth->abs_pressure, depth->temperature, depth->diff_pressure, depth->cal_pressure, depth->depth, depth->water_density);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DEPTH, (const char *)depth, MAVLINK_MSG_ID_DEPTH_MIN_LEN, MAVLINK_MSG_ID_DEPTH_LEN, MAVLINK_MSG_ID_DEPTH_CRC);
#endif
}

#if MAVLINK_MSG_ID_DEPTH_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_depth_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float abs_pressure, float temperature, float diff_pressure, float cal_pressure, float depth, float water_density)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, abs_pressure);
    _mav_put_float(buf, 4, temperature);
    _mav_put_float(buf, 8, diff_pressure);
    _mav_put_float(buf, 12, cal_pressure);
    _mav_put_float(buf, 16, depth);
    _mav_put_float(buf, 20, water_density);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DEPTH, buf, MAVLINK_MSG_ID_DEPTH_MIN_LEN, MAVLINK_MSG_ID_DEPTH_LEN, MAVLINK_MSG_ID_DEPTH_CRC);
#else
    mavlink_depth_t *packet = (mavlink_depth_t *)msgbuf;
    packet->abs_pressure = abs_pressure;
    packet->temperature = temperature;
    packet->diff_pressure = diff_pressure;
    packet->cal_pressure = cal_pressure;
    packet->depth = depth;
    packet->water_density = water_density;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DEPTH, (const char *)packet, MAVLINK_MSG_ID_DEPTH_MIN_LEN, MAVLINK_MSG_ID_DEPTH_LEN, MAVLINK_MSG_ID_DEPTH_CRC);
#endif
}
#endif

#endif

// MESSAGE DEPTH UNPACKING


/**
 * @brief Get field abs_pressure from depth message
 *
 * @return Absolute measured pressure
 */
static inline float mavlink_msg_depth_get_abs_pressure(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field temperature from depth message
 *
 * @return Measured temperature
 */
static inline float mavlink_msg_depth_get_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field diff_pressure from depth message
 *
 * @return Calculated Differential pressure
 */
static inline float mavlink_msg_depth_get_diff_pressure(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field cal_pressure from depth message
 *
 * @return Calibrated pressure at surface
 */
static inline float mavlink_msg_depth_get_cal_pressure(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field depth from depth message
 *
 * @return Calculated depth
 */
static inline float mavlink_msg_depth_get_depth(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field water_density from depth message
 *
 * @return Specific density of water used in depth calculation
 */
static inline float mavlink_msg_depth_get_water_density(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Decode a depth message into a struct
 *
 * @param msg The message to decode
 * @param depth C-struct to decode the message contents into
 */
static inline void mavlink_msg_depth_decode(const mavlink_message_t* msg, mavlink_depth_t* depth)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    depth->abs_pressure = mavlink_msg_depth_get_abs_pressure(msg);
    depth->temperature = mavlink_msg_depth_get_temperature(msg);
    depth->diff_pressure = mavlink_msg_depth_get_diff_pressure(msg);
    depth->cal_pressure = mavlink_msg_depth_get_cal_pressure(msg);
    depth->depth = mavlink_msg_depth_get_depth(msg);
    depth->water_density = mavlink_msg_depth_get_water_density(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DEPTH_LEN? msg->len : MAVLINK_MSG_ID_DEPTH_LEN;
        memset(depth, 0, MAVLINK_MSG_ID_DEPTH_LEN);
    memcpy(depth, _MAV_PAYLOAD(msg), len);
#endif
}
