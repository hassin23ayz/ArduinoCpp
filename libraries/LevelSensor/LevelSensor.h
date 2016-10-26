/*
  LevelSensor.h - Library for sensing the level of a tank whether its filled or empty.
  Hassin Ayaz.
  
  header file has all the definitions
*/


#ifndef LevelSensor_h         
#define LevelSensor_h

#define FILL 1
#define EMPTY 0
#define ERROR 255

#include "Arduino.h"    //gives you access to the standard types and constants of the Arduino language 

class LevelSensor             //have to create a object of this type to use the things that this class offers
{
  public:               //public parts are here
    
	LevelSensor(byte _fillpin, byte _emptypin);   //constructor
    byte isTankFilled(void);         //will return Tank is filled:1 or not:0   or 255
  
  private:              //private parts are here 
    byte state;         //Tank's state: 0 or 1 or 255
	byte fillpin;
	byte emptypin;
};
#endif