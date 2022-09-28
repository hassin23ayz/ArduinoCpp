#ifndef _MTB_H      //tells compiler to compile this class only once 
#define _MTB_H

#include <Arduino.h>
#include "Tyre.h"
#include "Frame.h"

class MTB
{
  public:
          MTB();
          void showSpec(void);
   private:
          Tyre* t;
          Frame* f;
};
#endif

