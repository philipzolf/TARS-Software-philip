/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.7 */

#ifndef PB_HILSIMPACKET_PB_H_INCLUDED
#define PB_HILSIMPACKET_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* TODO(Zyun): Might be more optimal to change all of this to required because protobuf for platformio
 adds an extra bool between each data package, which could lead to some data wastage */
typedef struct _HILSIMPacket {
    /* High-G IMU data */
    bool has_imu_high_ax;
    float imu_high_ax;
    bool has_imu_high_ay;
    float imu_high_ay;
    bool has_imu_high_az;
    float imu_high_az;
    /* Barometer data */
    bool has_barometer_altitude;
    float barometer_altitude;
    bool has_barometer_temperature;
    float barometer_temperature;
    bool has_barometer_pressure;
    float barometer_pressure;
    /* Low-G IMU data */
    bool has_imu_low_ax;
    float imu_low_ax;
    bool has_imu_low_ay;
    float imu_low_ay;
    bool has_imu_low_az;
    float imu_low_az;
    bool has_imu_low_gx;
    float imu_low_gx;
    bool has_imu_low_gy;
    float imu_low_gy;
    bool has_imu_low_gz;
    float imu_low_gz;
    /* Mag data */
    bool has_mag_x;
    float mag_x;
    bool has_mag_y;
    float mag_y;
    bool has_mag_z;
    float mag_z;
    /* Orientation data */
    bool has_ornt_roll;
    float ornt_roll;
    bool has_ornt_pitch;
    float ornt_pitch;
    bool has_ornt_yaw;
    float ornt_yaw;
} HILSIMPacket;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define HILSIMPacket_init_default                {false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0}
#define HILSIMPacket_init_zero                   {false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0, false, 0}

/* Field tags (for use in manual encoding/decoding) */
#define HILSIMPacket_imu_high_ax_tag             1
#define HILSIMPacket_imu_high_ay_tag             2
#define HILSIMPacket_imu_high_az_tag             3
#define HILSIMPacket_barometer_altitude_tag      4
#define HILSIMPacket_barometer_temperature_tag   5
#define HILSIMPacket_barometer_pressure_tag      6
#define HILSIMPacket_imu_low_ax_tag              7
#define HILSIMPacket_imu_low_ay_tag              8
#define HILSIMPacket_imu_low_az_tag              9
#define HILSIMPacket_imu_low_gx_tag              10
#define HILSIMPacket_imu_low_gy_tag              11
#define HILSIMPacket_imu_low_gz_tag              12
#define HILSIMPacket_mag_x_tag                   13
#define HILSIMPacket_mag_y_tag                   14
#define HILSIMPacket_mag_z_tag                   15
#define HILSIMPacket_ornt_roll_tag               16
#define HILSIMPacket_ornt_pitch_tag              17
#define HILSIMPacket_ornt_yaw_tag                18

/* Struct field encoding specification for nanopb */
#define HILSIMPacket_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, FLOAT,    imu_high_ax,       1) \
X(a, STATIC,   OPTIONAL, FLOAT,    imu_high_ay,       2) \
X(a, STATIC,   OPTIONAL, FLOAT,    imu_high_az,       3) \
X(a, STATIC,   OPTIONAL, FLOAT,    barometer_altitude,   4) \
X(a, STATIC,   OPTIONAL, FLOAT,    barometer_temperature,   5) \
X(a, STATIC,   OPTIONAL, FLOAT,    barometer_pressure,   6) \
X(a, STATIC,   OPTIONAL, FLOAT,    imu_low_ax,        7) \
X(a, STATIC,   OPTIONAL, FLOAT,    imu_low_ay,        8) \
X(a, STATIC,   OPTIONAL, FLOAT,    imu_low_az,        9) \
X(a, STATIC,   OPTIONAL, FLOAT,    imu_low_gx,       10) \
X(a, STATIC,   OPTIONAL, FLOAT,    imu_low_gy,       11) \
X(a, STATIC,   OPTIONAL, FLOAT,    imu_low_gz,       12) \
X(a, STATIC,   OPTIONAL, FLOAT,    mag_x,            13) \
X(a, STATIC,   OPTIONAL, FLOAT,    mag_y,            14) \
X(a, STATIC,   OPTIONAL, FLOAT,    mag_z,            15) \
X(a, STATIC,   OPTIONAL, FLOAT,    ornt_roll,        16) \
X(a, STATIC,   OPTIONAL, FLOAT,    ornt_pitch,       17) \
X(a, STATIC,   OPTIONAL, FLOAT,    ornt_yaw,         18)
#define HILSIMPacket_CALLBACK NULL
#define HILSIMPacket_DEFAULT NULL

extern const pb_msgdesc_t HILSIMPacket_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define HILSIMPacket_fields &HILSIMPacket_msg

/* Maximum encoded size of messages (where known) */
#define HILSIMPacket_size                        93

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
