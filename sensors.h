/* sensors.h */

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

/* Panel/Battery Voltage */
#define _PIN_SOLAR_V A1

/* Solar Irradiance */
#define _PIN_APOGEE_V A2
extern DallasTemperature dallas_amb_sen;

extern SHT1x sht1x;

extern Adafruit_BMP085 bmp085;
extern Adafruit_INA219 ina219_Solar;

/* Prototypes */
void Sensors_init(void);
int Sensors_sampleBatterymV(void);
int Sensors_samplePanelmV(void)
int Sensors_samplePressurepa(void);
int Sensors_sampleHumiditypct(void);
int Sensors_sampleSolarIrrmV(void);
int Sensors_sampleTemperaturedecic(void);
