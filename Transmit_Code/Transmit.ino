/* Transmit.ino */

/* Program libraries */
#include "transmit.h"
#include "sensors.h"
#include "schema.h"

/* Arduino Libraries */
#include <EEPROM.h>
#include <Wire.h>

/* External Libraries */
#include <XBee.h>
#include <stdint.h>
#include <overflow_checker.h>
#include <Adafruit_BMP085.h>
#include <OneWire.h>
#include <SHT1x.h>
#include <DallasTemperature.h>
#include <Adafruit_INA219.h>
#include <Adafruit_BMP085.h>

/* Global Variable for Packet */
schema_296_full G_Packet;
//schema_health G_health;

/* Global counter */
int count;

void setup()
{
    /* Variable Initialization */
    count = 0;

    /* Create Xbee Object */
    XBee G_xbee = XBee();

    /* Initialize Sensors */
    Sensors_init();

    /* Serial Initialization */
    Serial.begin(9600);
    G_xbee.begin(Serial);
    
    //initHealthSamples();

    delay(500);
}

void loop()
{
    Packet_Clear();
    Packet_Construct();
    Packet_Transmit(); 

    delay(500);

/*
    //Check health and run appropriate routine
    if(chkHealth() == NORMAL || chkHealth() == GOOD_SOLAR)
    {
        // Voltages are good to operate normally 
        Normal_Routine(&count);
    }
    else
    {
        // Voltages are not good, operate in powersave mode 
        PowerSave_Routine();
    }
*/
}

