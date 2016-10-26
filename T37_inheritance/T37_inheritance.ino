/*
 * this example shows the inheritance of c++ 
 * author: Hassin Ayaz
 * http://whileinthisloop.blogspot.com/
*/
#include "LM35.h"

LM35 myTempSensor;

void setup() 
{
  Serial.begin(9600);
  myTempSensor.init();
}

void loop() 
{
  Serial.print("raw ADC value: ");
  Serial.println(myTempSensor.readRawAdcValue());

  Serial.print("in mv: ");
  Serial.println(myTempSensor.readmv());

  Serial.print("in celsius: ");
  Serial.println(myTempSensor.readCelsius());

  Serial.print("in fahrenheit: ");
  Serial.println(myTempSensor.readFahrenheit());
  Serial.println("-----------------------------");
  delay(1000);
}
