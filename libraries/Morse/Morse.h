/*
  Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
  
  header file has all the definitions
  The core of the header file consists of a line for each function in the library,
  wrapped up in a class along with any variables you need:
*/
#ifndef Morse_h      //constructor
#define Morse_h

#include "Arduino.h"   //gives you access to the standard types and constants of the Arduino language 

class Morse              //have to create a object of this type to use the things that this class offers
{
  public:               //public parts are here
    Morse(int pin);
    void dot();
    void dash();
  private:              //private parts are here 
    int _pin;
};

#endif