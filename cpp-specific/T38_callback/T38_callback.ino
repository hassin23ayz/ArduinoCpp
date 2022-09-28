/*
 * this sketch will implement callBack using function pointer
 * Comm class will communicate to other device over serial
 * that other device will send a particular command upon which a 
 * function of the sketch will be called. this func is called 
 * the "callback function" in the sketch the run function of the 
 * Comm object is called continously
*/

#include "Comm.h"

#define TIMEOUT 3000       

void turnOnLed(void);
void turnOffLed(void);

Comm myComm(&turnOnLed, &turnOffLed); //Comm type object created

unsigned long displayT; 

void setup() 
{
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  Serial.println("Hi, send '1' to turn on or '0' to turn off the led");
  displayT = millis();
}

void loop() 
{
  if((millis()-displayT)>TIMEOUT)
  {
    displayT = millis();     //reset the displayT time variable 
    Serial.println("Hi, i am loop() .. just running some things");
  }
  
  myComm.Run();                     //continously running the comm process in the loop
  /*
   * other codes
   */
}

//callback functions 
//note: this functions are called from the Comm object thats why these functions are called "Callback Functions" 
void turnOnLed()
{
  Serial.println("LED turned On");
  digitalWrite(13,HIGH);
}

void turnOffLed()
{
  Serial.println("LED turned Off");
  digitalWrite(13,LOW);
}

