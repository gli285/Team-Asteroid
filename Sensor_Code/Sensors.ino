/********************************
*   File: Sensors.ino
*   REIS Weatherbox Firmware 
*
*   Test driver for sensors
********************************/

/* Arduino libraries */
#include <Wire.h>
#include <SoftwareSerial.h>

/* Program libraries */
#include "sensors.h"

/* Sensor libraries */
#include <SHT1x.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_INA219.h>
#include <Adafruit_BMP085.h>

/* Setup to initialize system. Initialies sensors, runs once */
void setup()
{
    Sensors_init();
    Serial.begin(9600);
}

/* Loop that runs constantly, unless stopped */
void loop()
{
    long Battery = -1;
    long Pressure = -1;
    long Panel = -1;
    long Humidity = -1;
    long SolarIrr = -1;
    long Temp = -1;

    Battery = Sensors_sampleBatterymV();
    delay(1000);
    Pressure = Sensors_samplePressurepa();
    delay(1000);
    Panel = Sensors_samplePanelmV();
    delay(1000);
    Humidity = Sensors_sampleHumiditypct();
    delay(1000);
    SolarIrr = Sensors_sampleSolarIrrmV();
    delay(1000);
    Temp = Sensors_sampleTemperaturedecic();
    delay(1000);


    Serial.println("***** Sensor Readings *****");
    
    Serial.print("Battery Data: ");
    Serial.println(Battery);

    Serial.print("Pressure Data: ");
    Serial.println(Pressure);

    Serial.print("Panel Data: ");
    Serial.println(Panel);

    Serial.print("Humidity Data: ");
    Serial.println(Humidity);

    Serial.print("Solar Irradiance Data: ");
    Serial.println(SolarIrr);

    Serial.print("Temperature Data: ");
    Serial.println(Temp);
}
