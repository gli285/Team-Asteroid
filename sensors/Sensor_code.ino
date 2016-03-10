/* Program Libraries */
#include "config.h"

/* Arduino Libraries */
#include <Wire.h>
#include <SoftwareSerial.h>

/* External libraries */
#include <SHT1x.h>
#include <Adafruit_BMP085.h>
#include <Adafruit_INA219.h>
#include <DallasTemperature.h>
#include <OneWire.h>

//Runs once, intializes
void setup()
{
	Sensors_init();
	Serial.begin(9600);
}

//Runs constantly after setup(), continues until stopped
void loop()
{
	int BatterymV = -1;
	int SolarIrrmV = -1;
	int Humiditypct = -1;
	int PanelmV = -1;
	int Pressurepa = -1;
	int Tempdecic = -1;

	BatterymV = Sensors_sampleBatterymV();
	delay(1000);
	SolarIrrmV = Sensors_sampleSolarIrrmV();
	delay(1000);
	Humiditypct = Sensors_sampleHumiditypct();	
	delay(1000);
	PanelmV = Sensors_samplePanelmV();
	delay(1000);
	Pressurepa = Sensors_samplePressurepa();
	delay(1000);
	Tempdecic = Sensors_sampleTemperaturedecic();
	delay(1000);

	Serial.print("--Sensor Readings--\n");
	Serial.print("\n");

	Serial.print("BatterymV Reading: ");
	Serial.println(BatterymV);
	
	Serial.print("SolarIrrmV Reading: ");
	Serial.println(SolarIrrmV);
	
	Serial.print("Humiditypct Reading: ");
	Serial.println(Humiditypct);
	
	Serial.print("PanelmV Reading: ");
	Serial.println(PanelmV);

	Serial.print("Pressurepa Reading: ");
	Serial.println(Pressurepa);
	
	Serial.print("Tempdecic Reading: ");
	Serial.println(Tempdecic);

}
