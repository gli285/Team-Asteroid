/************************************
 *     
 *     File: utilities.h
 *     REIS Weatherbox Firmware
 *
 *     Header file for utility functions
 *     
 ******************************************/

/* Program Libraries */
#include "schema.h"
#include "config.h"

/* External Libraries */
#include <EEPROM.h>
#include <XBee.h>

/* Check for previous includes */
#ifndef UTILITIES_H
#define UTILITIES_H

#define TRUE 1
#define FALSE 0

/* Power Management Macros */
#define ON 1
#define OFF 0c
#define ACTIVE 1
#define POWER_SAVE 0a

/* State of Health Macros */
#define NORMAL 0
#define GOOD_SOLAR 1
#define POOR 2


