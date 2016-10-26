#ifndef _LM35_H      //tells compiler to compile this class only once 
#define _LM35_H 

#include <Arduino.h>
#include "Sensor.h"

class LM35:public Sensor     //LM35 class inherits base class Sensor
{
   public:
          LM35();
          float readCelsius(void);
          float readFahrenheit(void);
};
#endif
