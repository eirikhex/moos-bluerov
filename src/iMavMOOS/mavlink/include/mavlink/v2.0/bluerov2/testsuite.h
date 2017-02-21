/** @file
 *    @brief MAVLink comm protocol testsuite generated from bluerov2.xml
 *    @see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef BLUEROV2_TESTSUITE_H
#define BLUEROV2_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_uAvionix(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_ardupilotmega(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_bluerov2(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_common(system_id, component_id, last_msg);
    mavlink_test_uAvionix(system_id, component_id, last_msg);
    mavlink_test_ardupilotmega(system_id, component_id, last_msg);
    mavlink_test_bluerov2(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"
#include "../uAvionix/testsuite.h"
#include "../ardupilotmega/testsuite.h"


static void mavlink_test_depth(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DEPTH >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_depth_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0
    };
    mavlink_depth_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.abs_pressure = packet_in.abs_pressure;
        packet1.temperature = packet_in.temperature;
        packet1.diff_pressure = packet_in.diff_pressure;
        packet1.cal_pressure = packet_in.cal_pressure;
        packet1.depth = packet_in.depth;
        packet1.water_density = packet_in.water_density;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DEPTH_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DEPTH_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_depth_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_depth_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_depth_pack(system_id, component_id, &msg , packet1.abs_pressure , packet1.temperature , packet1.diff_pressure , packet1.cal_pressure , packet1.depth , packet1.water_density );
    mavlink_msg_depth_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_depth_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.abs_pressure , packet1.temperature , packet1.diff_pressure , packet1.cal_pressure , packet1.depth , packet1.water_density );
    mavlink_msg_depth_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_depth_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_depth_send(MAVLINK_COMM_1 , packet1.abs_pressure , packet1.temperature , packet1.diff_pressure , packet1.cal_pressure , packet1.depth , packet1.water_density );
    mavlink_msg_depth_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_depth_calibration(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DEPTH_CALIBRATION >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_depth_calibration_t packet_in = {
        17.0,45.0,73.0
    };
    mavlink_depth_calibration_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.cal_depth = packet_in.cal_depth;
        packet1.cal_pressure = packet_in.cal_pressure;
        packet1.water_density = packet_in.water_density;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DEPTH_CALIBRATION_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DEPTH_CALIBRATION_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_depth_calibration_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_depth_calibration_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_depth_calibration_pack(system_id, component_id, &msg , packet1.cal_depth , packet1.cal_pressure , packet1.water_density );
    mavlink_msg_depth_calibration_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_depth_calibration_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.cal_depth , packet1.cal_pressure , packet1.water_density );
    mavlink_msg_depth_calibration_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_depth_calibration_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_depth_calibration_send(MAVLINK_COMM_1 , packet1.cal_depth , packet1.cal_pressure , packet1.water_density );
    mavlink_msg_depth_calibration_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_bluerov2(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_depth(system_id, component_id, last_msg);
    mavlink_test_depth_calibration(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // BLUEROV2_TESTSUITE_H
