#ifndef   COMM_H_     //tells compiler to compile this class only once 

#define   COMM_H_

#include <Arduino.h>

class Comm
{
//variables
public:
private:
  void (*funcPtrToTurnOnLed)(void);   //declares a function pointer
  void (*funcPtrToTurnOffLed)(void);  //declares a function pointer

//functions
public:
  Comm(void (*ptrOfaFuncToTurnOnLed)(), void (*ptrOfaFuncToTurnOffLed)());
  ~Comm();
  void Run(void); 
private:
};


#endif
