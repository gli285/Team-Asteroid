/* sensors.cpp */

#include "sensors.h"

/* Set Pins */
/* Temperature */
OneWire oneWire1(_PIN_AMB_TEMP);
DallasTemperature dallas_amb_sen(&oneWire1);
OneWire oneWire2(_PIN_ROOF_TEMP);
DallasTemperature dallas_roof_sen(&oneWire2);

/* Humidity */
SHT1x sht1x(_PIN_HUMID_DATA, _PIN_HUMID_CLK);

/* Pressure and Solar Irradiance */
Adafruit_BMP085 bmp085;
Adafruit_INA219 ina219_Solar;

/********************************
 *
 * Name:        Sensors_init
 * Returns:     Nothing
 * Parameter:   Nothing
 * Description: Initialize sensors from various libraries
 *
 * ******************************/
void Sensors_init(void)
{
	bmp085.begin();
	ina219_Solar.begin();	
}

/********************************
 *
 * Name:        Sensors_sampleBatterymV
 * Returns:     Battery voltage (mV)
 * Parameter:   Nothing
 * Description: Checks battery voltage
 *
 * ******************************/
int Sensors_sampleBatterymV(void)
{
	int value = analogRead(_PIN_BATT_V)*5000.0/1023;
	return value;
}


/********************************
 *
 * Name:        Sensors_samplePressure
 * Returns:     Pressure (pa)
 * Parameter:   Nothing
 * Description: Checks the current Pressure
 *
 * ******************************/
int Sensors_samplePressurepa(void)
{
	int value = 0;
	value = bmp085.readPressure();
	return value;
}

/********************************
 * Name:  	Sensors_samplePanelmV
 * Returns: 	Panel Voltage (mv)
 * Parameter: 	Nothing
 * Description: Checks the solar panel voltage 
 *
 * ******************************/	
int Sensors_samplePanelmV(void)
{
	int value = 2*analogRead(_PIN_SOLAR_v)*5000.0/1023;
	return value;
}


/********************************
 * Name:  	Sensors_sampleHumiditypct
 * Returns: 	Humidity (pct)
 * Parameter: 	Nothing
 * Description: Checks the current Humidity
 *
 * ******************************/	
int Sensors_sampleHumiditypct(void)
{
	int value = sht1x.readHumidity();
	return value;
}	

/********************************
 * Name:  	Sensors_sampleSolarIrrmV
 * Returns: 	Solar Irradiance voltage (mV)
 * Parameter: 	Nothing
 * Description: Checks the solar Irradiance level
 *
 * ******************************/	
int Sensors_sampleSolarIrrmV(void)
{
	int value = analogRead(_PIN_APOGEE_V)*5000.0/1023;
	return value;
}

/********************************
 * Name:  	Sensors_sampleTemperaturedecic
 * Returns: 	Temperature (C)
 * Parameter: 	Nothing
 * Description: Checks the current temperature
 *
 * ******************************/	
int Sensors_sampleTemperaturedecic(void)
{
	int value = bmp085.readTemperature()*10;
	return value;
}

