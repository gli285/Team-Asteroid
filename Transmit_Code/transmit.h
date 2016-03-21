/* transmit.h */

#include "schema.h"
#include "sensors.h"

/* External Libraries */
#include <EEPROM.h>
#include <XBee.h>
#include <overflow_checker.h>

/* Check for previous includes */
#ifndef TRANSMIT_H
#define TRANSMIT_H

/* Global variable for packet */
extern schema_1 G_Packet;

/* Packet Clear */
void Packet_Clear();

/* Packet Construction */
void Packet_Construct();

/* Packet Transmit */
void Packet_Transmit();

#endif
