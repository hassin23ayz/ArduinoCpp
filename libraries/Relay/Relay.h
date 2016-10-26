/*
  Relay.h - Library for controlling relay.
  Hassin Ayaz.
  
  header file has all the definitions
*/


#ifndef Relay_h         
#define Relay_h

#include "Arduino.h"    //gives you access to the standard types and constants of the Arduino language

#define OVER true
#define UNDER false

class Relay             //have to create a object of this type to use the things that this class offers
{
  public:               //public parts are here
    
	Relay(byte _pin);   //constructor
    boolean GetRelayState(void);         //will return relay's state 1:ON 0:off
    void OnOffuponCurrent(float current, float maxCurrent);  //relay will operate according to the current flowing through 
	void OnOffuponTankLevels(byte Ltank, byte Utank);  //if combination is 1,0 then relay will be turned on
	void turnOffRelay(void);
	void turnOnRelay(void);
  
  private:              //private parts are here 
    boolean state;      //Relay'state: 0 or 1
	byte pin;
};
#endif