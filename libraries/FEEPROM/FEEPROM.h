/*
  FEEPROM.h - Library for saving float type value in eeprom in a circular buffer style.
  Created by hassin Ayaz, May 7, 2015.
  
  header file has all the definitions
  The core of the header file consists of a line for each function in the library,
  wrapped up in a class along with any variables you need:
*/
#ifndef FEEPROM_h      //constructor
#define FEEPROM_h

#include "Arduino.h"   //gives you access to the standard types and constants of the Arduino language
#include <EEPROM.h>    //standard EEPROM library 

class FEEPROM              //have to create a object of this type to use the things that this class offers
{
  public:                              //public parts are here
    FEEPROM(word sA, word eA);
	void clearAllFEEPROM(void);	
    void writeCircularFEEPROM(float f);
    float readMaxFEEPROM(void);
  private:                              //private parts are here 
    word startAdd, endAdd;
};

#endif