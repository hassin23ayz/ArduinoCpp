#ifndef _SENSOR_H      //tells compiler to compile this class only once 
#define _SENSOR_H 

#include <Arduino.h>

class Sensor
{
   public:
          Sensor();
          void init(void);
          uint16_t readRawAdcValue(void);
          float readmv(void);
};
#endif
