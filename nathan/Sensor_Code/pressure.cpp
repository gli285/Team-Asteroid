/* BMP085 Pressure sensor */
/* Connection
   	Connect VCC of the BMP085 sensor to 3.3V (NOT 5.0V!)
   	Connect GND to Ground
   	Connect SCL to i2c clock - on '168/'328 Arduino Uno/Duemilanove/etc thats Analog 5
   	Connect SDA to i2c data - on '168/'328 Arduino Uno/Duemilanove/etc thats Analog 4
   	EOC is not used, it signifies an end of conversion
   	XCLR is a reset pin, also not used here
*/
/* Functions
 	constructor:
	Adafruit_BMP085 variable;

	readTemperature()
	readPressure()
	readAltitude()
	readSealevelPressure()
	readAltutide(number)
*/
/* Pressure sensor libraries
 	#include <Wire.h>
	#include <Adafruit_BMP085.h>
*/
#include <Wire.h>
#include <Adafruit_BMP085.h>

Adafruit_BMP085 pressureSensor;
void setup()
{
	Serial.Begin(9600);
}

void loop()
{
	float pressure = pressureSensor.readPressure();
	Serial.println(pressure);
}
 
