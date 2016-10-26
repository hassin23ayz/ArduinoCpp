/*
  PumpMotorAPL.cpp - source code for controlling both WASa & ROOF motors 
  header file has all the definitions
*/

#include "Arduino.h"
#include "PumpMotorAPL.h"

PumpMotorAPL::PumpMotorAPL()   //constructor this is called when a object of PumpMotorAPL type is created
{
  //internal pull up of the input sensors   
  pinMode(RSV_FL_SENS_1, INPUT_PULLUP);
  pinMode(RSV_FL_SENS_2, INPUT_PULLUP);
  pinMode(ROOF_FL_SENS_1, INPUT_PULLUP);
  pinMode(ROOF_FL_SENS_2, INPUT_PULLUP); 
 
 //output mode setting
  pinMode(UP_M_ON,OUTPUT);
  pinMode(UP_M_OFF, OUTPUT);
  pinMode(W_M_ON, OUTPUT);
  pinMode(W_M_OFF, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  
  //initially all of the controlling outputs are low
  digitalWrite(UP_M_ON, LOW);          //for single phase motor controlling only this pin is used
  digitalWrite(W_M_ON, LOW);           //for single phase wasa motor controlling
  digitalWrite(BUZZER, LOW);           //BUZZER is off at first considering no error 
}

void PumpMotorAPL::monitorLevel(void)        //public function which will sense the level sensors & act accordingly  
{
  if(RSV_EMPTY)
    {
    digitalWrite(W_M_ON, HIGH);         //wasa motor is turned on
    }
  else
   {
    digitalWrite(W_M_ON, LOW);          //wasa motor is turned off
   } 
  //controlling of motor
  if(RSV_FULL && ROOF_EMPTY)
    {
    digitalWrite(UP_M_ON, HIGH);        //up motor is turned on
    }
  if(ROOF_FULL || RSV_EMPTY)
    { 
    digitalWrite(UP_M_ON, LOW);         //up motor is turned off
    }  
  //error sensing 
  if(RSV_SENS_ERR)                      //reserve sensor error sensing
    { 
    digitalWrite(BUZZER, HIGH);
    }
  else
    {
    digitalWrite(BUZZER, LOW);
    }
  if(ROOF_SENS_ERR)                      //roof sensor error sensing
    {
    digitalWrite(BUZZER, HIGH);
    }
  else
    { 
    digitalWrite(BUZZER, LOW);
    }
}

void PumpMotorAPL::monitorCurrent(byte hp, float current)    //public function which will see if overcurrent flows and act accordingly 
{
  //_hp = hp;
  //current = i;
  switch(hp) 
   {
   case 0:
   if(current>CONS)digitalWrite(UP_M_ON, LOW);   //up motor is turned off
   break;
   case 1:
   if(current>RARE)digitalWrite(UP_M_ON, LOW);   //up motor is turned off
   break;
   case 2:
   if(current>RURAL)digitalWrite(UP_M_ON, LOW);   //up motor is turned off
   break;
   case 3:
   if(current>VILL)digitalWrite(UP_M_ON, LOW);   //up motor is turned off 
   break;
   case 4:
   if(current>GENERAL)digitalWrite(UP_M_ON, LOW);   //up motor is turned off
   break;
   case 5:
   if(current>TOWN)digitalWrite(UP_M_ON, LOW);   //up motor is turned off
   break;
   case 6:
   if(current>CITY)digitalWrite(UP_M_ON, LOW);   //up motor is turned off
   break;
   case 7:
   if(current>RES)digitalWrite(UP_M_ON, LOW);   //up motor is turned off
   break;              
   case 8:
   if(current>INDUS)digitalWrite(UP_M_ON, LOW);   //up motor is turned off
   break;
   } 
}