/** @file
 *    @brief MAVLink comm protocol testsuite generated from heatpoints.xml
 *    @see https://mavlink.io/en/
 */
#pragma once
#ifndef HEATPOINTS_TESTSUITE_H
#define HEATPOINTS_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_heatpoints(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_common(system_id, component_id, last_msg);
    mavlink_test_heatpoints(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_heatpoint(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_HEATPOINT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_heatpoint_t packet_in = {
        17.0,45.0,29
    };
    mavlink_heatpoint_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.lat = packet_in.lat;
        packet1.lon = packet_in.lon;
        packet1.color_intensity = packet_in.color_intensity;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_HEATPOINT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_HEATPOINT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_heatpoint_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_heatpoint_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_heatpoint_pack(system_id, component_id, &msg , packet1.lat , packet1.lon , packet1.color_intensity );
    mavlink_msg_heatpoint_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_heatpoint_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.lat , packet1.lon , packet1.color_intensity );
    mavlink_msg_heatpoint_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_heatpoint_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_heatpoint_send(MAVLINK_COMM_1 , packet1.lat , packet1.lon , packet1.color_intensity );
    mavlink_msg_heatpoint_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("HEATPOINT") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_HEATPOINT) != NULL);
#endif
}

static void mavlink_test_heatpoints(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_heatpoint(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // HEATPOINTS_TESTSUITE_H
