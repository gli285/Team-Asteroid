/* SHT1x Humidity sensor */
/* Functions
  
	 readTemperatureC()
  	 readTemperatureF()
	 readHumidity()
*/


//Humidity Sensor library
#include <SHT1x.h>

#define dataPin 10
#define clockPin 11
humiditySensor sht1x(dataPin, clockPin);


void setup()
{
	Serial.begin(9600);
}

void loop()
{
	float humidity;
	humidity = humiditySensor.readHumidity();

	printf("humidity value is %f", humidity);

	delay(2000);
}


