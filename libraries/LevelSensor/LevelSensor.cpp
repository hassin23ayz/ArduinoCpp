//all the functions are defined in the header file .cpp file have the constructor the wrapped up class is in the header file


#include "Arduino.h" // Access to standard arduino functions 
#include "LevelSensor.h"   // corresponding header file

LevelSensor::LevelSensor(byte _fillpin, byte _emptypin)  //constructor
{
  fillpin = _fillpin;
  emptypin = _emptypin;
  //pinMode(fillpin, INPUT_PULLUP);                    //pin set in input mode with input pullup resistor being used
  //pinMode(emptypin, INPUT_PULLUP);
  pinMode(fillpin, INPUT);                   
  pinMode(emptypin, INPUT);  
}

byte LevelSensor::isTankFilled(void)
{
if((digitalRead(fillpin)==HIGH)&&(digitalRead(emptypin)==LOW))     //fillpin=HIGH ***** emptypin=LOW ***** state = FILL
  state = FILL;
else if((digitalRead(fillpin)==LOW)&&(digitalRead(emptypin)==HIGH))  //fillpin=LOW ***** emptypin=HIGH ***** state = EMPTY
  state = EMPTY;
else
  state = ERROR; 
return state;
}

 