/******************************************
 *
 *    File: routines.h
 *    REIS Weatherbox Firmware
 *
 *    Main file that contains various routines
 *         for weatherbox operation.
 *    
 *******************************************/

/* Program Libraries */
#include "transmit.h"
#include "utilities.h"

/* Check for previous includes */
#ifndef ROUTINES_H
#define ROUTINES_H

/* Healthy Routine */
void Normal_Routine(int *count);

/* Unhealthy Routine */
void PowerSave_Routine(void);

#endif
