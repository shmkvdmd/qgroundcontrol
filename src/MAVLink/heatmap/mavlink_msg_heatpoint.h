#pragma once
// MESSAGE HEATPOINT PACKING

#define MAVLINK_MSG_ID_HEATPOINT 555

#include <cstdint>

typedef struct __mavlink_heatpoint_t {
 float lat; /*<  Latitude*/
 float lon; /*<  Longitude*/
 uint8_t color_intensity; /*<  Color intensity*/
} mavlink_heatpoint_t;

#define MAVLINK_MSG_ID_HEATPOINT_LEN 9
#define MAVLINK_MSG_ID_HEATPOINT_MIN_LEN 9
#define MAVLINK_MSG_ID_555_LEN 9
#define MAVLINK_MSG_ID_555_MIN_LEN 9

#define MAVLINK_MSG_ID_HEATPOINT_CRC 37
#define MAVLINK_MSG_ID_555_CRC 37



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_HEATPOINT { \
    555, \
    "HEATPOINT", \
    3, \
    {  { "lat", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_heatpoint_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_heatpoint_t, lon) }, \
         { "color_intensity", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_heatpoint_t, color_intensity) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_HEATPOINT { \
    "HEATPOINT", \
    3, \
    {  { "lat", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_heatpoint_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_heatpoint_t, lon) }, \
         { "color_intensity", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_heatpoint_t, color_intensity) }, \
         } \
}
#endif

/**
 * @brief Pack a heatpoint message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param lat  Latitude
 * @param lon  Longitude
 * @param color_intensity  Color intensity
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_heatpoint_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float lat, float lon, uint8_t color_intensity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HEATPOINT_LEN];
    _mav_put_float(buf, 0, lat);
    _mav_put_float(buf, 4, lon);
    _mav_put_uint8_t(buf, 8, color_intensity);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HEATPOINT_LEN);
#else
    mavlink_heatpoint_t packet;
    packet.lat = lat;
    packet.lon = lon;
    packet.color_intensity = color_intensity;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HEATPOINT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HEATPOINT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HEATPOINT_MIN_LEN, MAVLINK_MSG_ID_HEATPOINT_LEN, MAVLINK_MSG_ID_HEATPOINT_CRC);
}

/**
 * @brief Pack a heatpoint message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param lat  Latitude
 * @param lon  Longitude
 * @param color_intensity  Color intensity
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_heatpoint_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               float lat, float lon, uint8_t color_intensity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HEATPOINT_LEN];
    _mav_put_float(buf, 0, lat);
    _mav_put_float(buf, 4, lon);
    _mav_put_uint8_t(buf, 8, color_intensity);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HEATPOINT_LEN);
#else
    mavlink_heatpoint_t packet;
    packet.lat = lat;
    packet.lon = lon;
    packet.color_intensity = color_intensity;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HEATPOINT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HEATPOINT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_HEATPOINT_MIN_LEN, MAVLINK_MSG_ID_HEATPOINT_LEN, MAVLINK_MSG_ID_HEATPOINT_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_HEATPOINT_MIN_LEN, MAVLINK_MSG_ID_HEATPOINT_LEN);
#endif
}

/**
 * @brief Pack a heatpoint message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lat  Latitude
 * @param lon  Longitude
 * @param color_intensity  Color intensity
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_heatpoint_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float lat,float lon,uint8_t color_intensity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HEATPOINT_LEN];
    _mav_put_float(buf, 0, lat);
    _mav_put_float(buf, 4, lon);
    _mav_put_uint8_t(buf, 8, color_intensity);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HEATPOINT_LEN);
#else
    mavlink_heatpoint_t packet;
    packet.lat = lat;
    packet.lon = lon;
    packet.color_intensity = color_intensity;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HEATPOINT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HEATPOINT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_HEATPOINT_MIN_LEN, MAVLINK_MSG_ID_HEATPOINT_LEN, MAVLINK_MSG_ID_HEATPOINT_CRC);
}

/**
 * @brief Encode a heatpoint struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param heatpoint C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_heatpoint_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_heatpoint_t* heatpoint)
{
    return mavlink_msg_heatpoint_pack(system_id, component_id, msg, heatpoint->lat, heatpoint->lon, heatpoint->color_intensity);
}

/**
 * @brief Encode a heatpoint struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param heatpoint C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_heatpoint_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_heatpoint_t* heatpoint)
{
    return mavlink_msg_heatpoint_pack_chan(system_id, component_id, chan, msg, heatpoint->lat, heatpoint->lon, heatpoint->color_intensity);
}

/**
 * @brief Encode a heatpoint struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param heatpoint C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_heatpoint_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_heatpoint_t* heatpoint)
{
    return mavlink_msg_heatpoint_pack_status(system_id, component_id, _status, msg,  heatpoint->lat, heatpoint->lon, heatpoint->color_intensity);
}

/**
 * @brief Send a heatpoint message
 * @param chan MAVLink channel to send the message
 *
 * @param lat  Latitude
 * @param lon  Longitude
 * @param color_intensity  Color intensity
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_heatpoint_send(mavlink_channel_t chan, float lat, float lon, uint8_t color_intensity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HEATPOINT_LEN];
    _mav_put_float(buf, 0, lat);
    _mav_put_float(buf, 4, lon);
    _mav_put_uint8_t(buf, 8, color_intensity);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEATPOINT, buf, MAVLINK_MSG_ID_HEATPOINT_MIN_LEN, MAVLINK_MSG_ID_HEATPOINT_LEN, MAVLINK_MSG_ID_HEATPOINT_CRC);
#else
    mavlink_heatpoint_t packet;
    packet.lat = lat;
    packet.lon = lon;
    packet.color_intensity = color_intensity;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEATPOINT, (const char *)&packet, MAVLINK_MSG_ID_HEATPOINT_MIN_LEN, MAVLINK_MSG_ID_HEATPOINT_LEN, MAVLINK_MSG_ID_HEATPOINT_CRC);
#endif
}

/**
 * @brief Send a heatpoint message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_heatpoint_send_struct(mavlink_channel_t chan, const mavlink_heatpoint_t* heatpoint)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_heatpoint_send(chan, heatpoint->lat, heatpoint->lon, heatpoint->color_intensity);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEATPOINT, (const char *)heatpoint, MAVLINK_MSG_ID_HEATPOINT_MIN_LEN, MAVLINK_MSG_ID_HEATPOINT_LEN, MAVLINK_MSG_ID_HEATPOINT_CRC);
#endif
}

#if MAVLINK_MSG_ID_HEATPOINT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_heatpoint_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float lat, float lon, uint8_t color_intensity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, lat);
    _mav_put_float(buf, 4, lon);
    _mav_put_uint8_t(buf, 8, color_intensity);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEATPOINT, buf, MAVLINK_MSG_ID_HEATPOINT_MIN_LEN, MAVLINK_MSG_ID_HEATPOINT_LEN, MAVLINK_MSG_ID_HEATPOINT_CRC);
#else
    mavlink_heatpoint_t *packet = (mavlink_heatpoint_t *)msgbuf;
    packet->lat = lat;
    packet->lon = lon;
    packet->color_intensity = color_intensity;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEATPOINT, (const char *)packet, MAVLINK_MSG_ID_HEATPOINT_MIN_LEN, MAVLINK_MSG_ID_HEATPOINT_LEN, MAVLINK_MSG_ID_HEATPOINT_CRC);
#endif
}
#endif

#endif

// MESSAGE HEATPOINT UNPACKING


/**
 * @brief Get field lat from heatpoint message
 *
 * @return  Latitude
 */
static inline float mavlink_msg_heatpoint_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field lon from heatpoint message
 *
 * @return  Longitude
 */
static inline float mavlink_msg_heatpoint_get_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field color_intensity from heatpoint message
 *
 * @return  Color intensity
 */
static inline uint8_t mavlink_msg_heatpoint_get_color_intensity(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Decode a heatpoint message into a struct
 *
 * @param msg The message to decode
 * @param heatpoint C-struct to decode the message contents into
 */
static inline void mavlink_msg_heatpoint_decode(const mavlink_message_t* msg, mavlink_heatpoint_t* heatpoint)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    heatpoint->lat = mavlink_msg_heatpoint_get_lat(msg);
    heatpoint->lon = mavlink_msg_heatpoint_get_lon(msg);
    heatpoint->color_intensity = mavlink_msg_heatpoint_get_color_intensity(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_HEATPOINT_LEN? msg->len : MAVLINK_MSG_ID_HEATPOINT_LEN;
        memset(heatpoint, 0, MAVLINK_MSG_ID_HEATPOINT_LEN);
    memcpy(heatpoint, _MAV_PAYLOAD(msg), len);
#endif
}
