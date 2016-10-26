//all the functions are defined in the header file .cpp file have the constructor the wrapped up class is in the header file


#include "Arduino.h" // Access to standard arduino functions 
#include "Morse.h"   // access to the definitions of the hmorse header file

Morse::Morse(int pin)  //constructor when a object of this type is created this constructor is called 
{
  pinMode(pin, OUTPUT);  // instructions which will be executed when object is created  
  _pin = pin;
}

void Morse::dot()  //Class name::funtion name 
{
  digitalWrite(_pin, HIGH);
  delay(250);
  digitalWrite(_pin, LOW);
  delay(250);  
}

void Morse::dash()
{
  digitalWrite(_pin, HIGH);
  delay(1000);
  digitalWrite(_pin, LOW);
  delay(250);
}

 