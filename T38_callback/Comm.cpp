#include "Comm.h"

//constructor
Comm::Comm(void (*ptrOfaFuncToTurnOnLed)(), void (*ptrOfaFuncToTurnOffLed)())
{
  //assigns the address of the functions to be called back 
  //to the appropriate function pointers
  
  funcPtrToTurnOnLed = ptrOfaFuncToTurnOnLed;    
  funcPtrToTurnOffLed = ptrOfaFuncToTurnOffLed;  
}

//destructor
Comm::~Comm()
{}

void Comm::Run(void)
{
  Serial.flush();      //Waits for the transmission of outgoing serial data to complete.
  
  if(Serial.available()>0)
  {
    char ch = Serial.read();
    if(ch == '1')
    {
      //call the turnOnLed() function in the sketch by calling the corresponding function pointer
      funcPtrToTurnOnLed();
    }
    if(ch == '0')
    {
      //call the turnOffLed() function in the sketch by calling the corresponding function pointer
      funcPtrToTurnOffLed();  
    }
  }
}

