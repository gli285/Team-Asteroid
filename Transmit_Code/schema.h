/* schema.h */

#include <stdint.h>

/* Check for previous includes */
#ifndef SCHEMA_H
#define SCHEMA_H

#define MAX_SIZE 100 


/* Pin configuations for ATMEGA 328P Microcontroller */
/* Receiver and transmitter pins */
#define _PIN_RX 0
#define _PIN_TX 1

/* XBEE */
#define _PIN_XBEE_TX 0
#define _PIN_XBEE_RX 1
#define _PIN_XBEE_SLEEP 13

/* Temperature */
#define _PIN_TEMP 3

/* Humidity */
#define _PIN_HUMID_CLK 7
#define _PIN_HUMID_DATA 8

/* Solar Panel and Battery Voltage */
#define _PIN_SOLAR_V A1
#define _PIN_BATT_V A3

/* Solar Irradiance */
#define _PIN_SOLAR_IRR A2


/* Struct for binary packet transfer */
typedef struct {
    uint16_t schema = 297;        // Schema number
    uint16_t address;	       	// Address of Arduino	
    uint32_t uptime_ms;	       	// Time since start of program
    uint16_t batt_mv[6];   	// Battery Voltage (in milli volts)
    uint16_t panel_mv[6];  	// Panel Voltage (in milli volts)
    uint32_t bmp085_press_pa;	// Pressure Value (in pascals)
    int16_t bmp085_temp_decic;  // Temperature Value (in celsius)
    uint16_t humidity_centi_pct; // Humidity value (centi_pascals)
    uint16_t apogee_w_m2[20];    // Solar Irradiance (millivolts)
} schema_296_full;

/* Struct for health check */
typedef struct {
    uint16_t schema;        // Schema ID number
    uint16_t address;       // Address of Arduino
    uint32_t uptime_ms;     // Time since the start of program
    uint16_t batt_mv;       // Battery voltage (millivolts)
} schema_5;

typedef schema_5 schema_health; 

#endif
