/*
 * T36 auto initialization of private variable at constructor
 * Author: Hassin Ayaz
*/

#include "CustomLCD.h"

CustomLCD myCustomLCD;   //CustomLCD object is created

void setup() 
{
  Serial.begin(9600);
  myCustomLCD.showSomething();
}

void loop() 
{}
