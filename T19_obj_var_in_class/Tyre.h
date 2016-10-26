#ifndef _TYRE_H      //tells compiler to compile this class only once 
#define _TYRE_H

#include <Arduino.h>

class Tyre
{
  public:
        Tyre(byte _size);
        void printTyreSize(void);
  private:
        byte tsize;
  
};
#endif


