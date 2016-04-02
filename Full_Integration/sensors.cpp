/* sensors.cpp */

#include "sensors.h"

/* Set Pins */
/* Temperature */
OneWire oneWire(_PIN_ROOF_TEMP);
DallasTemperature dallas_sen(&oneWire);

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
    dallas_sen.begin();
}

/********************************
 *
 * Name:        Sensors_sampleBatterymV
 * Returns:     Battery voltage (mV)
 * Parameter:   Nothing
 * Description: Checks battery voltage
 *
 * ******************************/
uint16_t Sensors_sampleBatterymV(void)
{
	uint16_t value = analogRead(_PIN_BATT_V)*5000.0/1023;
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
uint32_t Sensors_samplePressurepa(void)
{
	uint32_t value = 0;
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
uint16_t Sensors_samplePanelmV(void)
{
	uint16_t value = 2*analogRead(_PIN_SOLAR_V)*5000.0/1023;
	return value;
}


/********************************
 * Name:  	Sensors_sampleHumiditypct
 * Returns: 	Humidity (pct)
 * Parameter: 	Nothing
 * Description: Checks the current Humidity
 *
 * ******************************/	
uint16_t Sensors_sampleHumiditypct(void)
{
	uint16_t value = sht1x.readHumidity();
	return value;
}	

/********************************
 * Name:  	Sensors_sampleSolarIrrmV
 * Returns: 	Solar Irradiance voltage (mV)
 * Parameter: 	Nothing
 * Description: Checks the solar Irradiance level
 *
 * ******************************/	
uint16_t Sensors_sampleSolarIrrmV(void)
{
	uint16_t value = analogRead(_PIN_APOGEE_V)*5000.0/1023;
	return value;
}

/********************************
 * Name:  	Sensors_sampleTemperaturedecic
 * Returns: 	Temperature (C)
 * Parameter: 	Nothing
 * Description: Checks the current temperature
 *
 * ******************************/	
int16_t Sensors_sampleTemperaturedecic(void)
{
    byte i;
    byte present = 0;
    byte type_s;
    byte data[12];
    byte addr[8];
    int16_t celsius, fahrenheit;

    if(!oneWire.search(addr))
    {
        Serial.println();
        oneWire.reset_search();
    }

    if(OneWire::crc8(addr, 7) != addr[7])
    {
        Serial.println("CRC is not valid!");
    }

    oneWire.reset();
    oneWire.select(addr);
    oneWire.write(0x44, 1);

    delay(1000);

    present = oneWire.reset();
    oneWire.select(addr);
    oneWire.write(0xBE);

    for(int i = 0; i < 9; i++)
    {
        data[i] = oneWire.read();

        /* DEBUG */
        //Serial.print(data[i], HEX);
        //Serial.print(" ");
    }
    
    /* Convert data to actual temperature */

    int16_t raw = (data[1] << 8) | data[0];
    if(type_s)
    {
        /* 9 bit resolution default */
        raw = raw << 3;
        /* Gives full 12 bit resolution */
        if(data[7] == 0x10)
        {
            raw = (raw &0xFFF0) + 12 - data[6];
        }
    }
    else
    {
        byte cfg = (data[4] &0x60);

        /* At lower res, the low bits are undefined, so let's zero them */
        /* 9 bit resolution, 93.75 ms */
        if(cfg == 0x00)
        {
            raw = raw &~7;
        }
        /* 10 bit resolution, 187.5 ms */
        else if(cfg == 0x20)
        {
            raw = raw &~3;
        }
        /* 11 bit resolution, 375 ms */
        else if(cfg == 0x40)
        {
            raw = raw &~1;
        }
    }

    /* Return data in celsius */
    celsius = (int16_t)raw/16.0;

    return celsius;
    
    /* Returns data in fahrenheit */
    //fahrenheit = celsius * 1.8 + 32.0;
    //return fahrenheit;
}


