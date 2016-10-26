//all the functions are defined in the header file .cpp file have the constructor the wrapped up class is in the header file


#include "Arduino.h" // Access to standard arduino functions 
#include "Relay.h"   // corresponding header file

Relay::Relay(byte _pin)  //constructor
{
  pin = _pin;
  pinMode(pin, OUTPUT);                    //pin set in output mode 
  digitalWrite(pin, LOW);                  //Relay is off at first
}

void Relay::OnOffuponCurrent(float current,float maxCurrent)        //this function will check current w.r.t. maxCurrent
{
  if(current>maxCurrent)
    {
    digitalWrite(pin, LOW);
	}
  else
    {
    digitalWrite(pin, HIGH);
	}
}

void Relay::OnOffuponTankLevels(byte Ltank, byte Utank)
{
  if((Ltank==1)&&(Utank==0))
    digitalWrite(pin, HIGH);
  else
    digitalWrite(pin, LOW);
}

boolean Relay::GetRelayState(void)
{
  state = digitalRead(pin);
  return state;
}

void Relay::turnOffRelay(void)
{
  digitalWrite(pin, LOW);
  //delay(100);
}

void Relay::turnOnRelay(void)
{
  digitalWrite(pin, HIGH);
  //delay(100);
}
  