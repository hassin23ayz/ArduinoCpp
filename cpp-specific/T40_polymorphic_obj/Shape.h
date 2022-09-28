#ifndef _SHAPE_H      //tells compiler to compile this class only once 
#define _SHAPE_H

#include <Arduino.h>

//this is the base class
class Shape          
{
  public: 
          Shape();                      //constructor
          ~Shape();                     //destructor
          virtual void printType(void); //the virtual function which will serve polymorphism 
};

#endif 
