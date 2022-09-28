#ifndef _FRAME_H      //tells compiler to compile this class only once 
#define _FRAME_H

#include <Arduino.h>

class Frame
{
  public:
        Frame(char* ptrType);
        void printFrameType(void);
  private:
        char type[30];
  
};
#endif
