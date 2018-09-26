/**
 * Ruuvi communication interface
 *
 * License: BSD-3
 * Author: Otso Jousimaa <otso@ojousima.net>
 */
#ifndef RUUVI_INTERFACE_COMMUNICATION_H
#define RUUVI_INTERFACE_COMMUNICATION_H
#include "ruuvi_driver_error.h"
#include <stdint.h>
#include <stdbool.h>

// Standard BLE Broadcast manufacturer specific data payload length
#define RUUVI_INTERFACE_COMMUNICATION_MESSAGE_MAX_LENGTH 24

typedef struct{
  uint8_t data[RUUVI_INTERFACE_COMMUNICATION_MESSAGE_MAX_LENGTH];
  uint8_t data_length;
  bool repeat;
}ruuvi_interface_communication_message_t;

typedef enum {
  RUUVI_INTERFACE_COMMUNICATION_CONNECTED,
  RUUVI_INTERFACE_COMMUNICATION_DISCONNECTED,
  RUUVI_INTERFACE_COMMUNICATION_SENT,
  RUUVI_INTERFACE_COMMUNICATION_RECEIVED,
}ruuvi_interface_communication_evt_t;

typedef struct ruuvi_interface_communication_t ruuvi_interface_communication_t;          // forward declaration *and* typedef
typedef ruuvi_driver_status_t(*ruuvi_interface_communication_xfer_fp_t)(ruuvi_interface_communication_message_t*);
typedef ruuvi_driver_status_t(*ruuvi_interface_communication_init_fp_t)(ruuvi_interface_communication_t* const);
typedef ruuvi_driver_status_t(*ruuvi_interface_communication_evt_handler_fp_t)(const ruuvi_interface_communication_evt_t);

// Every Ruuvi communication channel must  be able to send data and receive data.
// Channels can be init or uninit
struct ruuvi_interface_communication_t
{
  ruuvi_interface_communication_xfer_fp_t        send;
  ruuvi_interface_communication_xfer_fp_t        read;
  ruuvi_interface_communication_init_fp_t        init;
  ruuvi_interface_communication_init_fp_t        uninit;
  ruuvi_interface_communication_evt_handler_fp_t on_evt;
};

#endif