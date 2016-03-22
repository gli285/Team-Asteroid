/* sensors.h */

/* Check for previous includes */
#ifndef SENSORS_H
#define SENSORS_H

/* Arduino libraries */
#include <Wire.h>
#include <SoftwareSerial.h>

/* External Libraries */
#include <SHT1x.h>
#include <Adafruit_BMP085.h>
#include <Adafruit_INA219.h>
#include <DallasTemperature.h>
#include <OneWire.h>

/* Humidity */
#define _PIN_HUMID_CLK 7
#define _PIN_HUMID_DATA 8

/* Battery */
#define _PIN_BATT_V A3

/* Panel Voltage */
#define _PIN_SOLAR_V A1

/* Temperature */
#define _PIN_ROOF_TEMP 3

/* Solar Irradiance */
#define _PIN_APOGEE_V A2

/* Prototypes */
void Sensors_init(void);
uint16_t Sensors_sampleBatterymV(void);
uint32_t Sensors_samplePressurepa(void);
uint16_t Sensors_samplePanelmV(void);
uint16_t Sensors_sampleHumiditypct(void);
uint16_t Sensors_sampleSolarIrrmV(void);
int16_t Sensors_sampleTemperaturedecic(void);

#endif
