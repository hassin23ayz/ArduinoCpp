#ifndef _MTB_H      //tells compiler to compile this class only once 
#define _MTB_H

#include <Arduino.h>

class MTB
{
  public:
          static byte noOfMtb;
          static void noOfMtbsMade(void);
          MTB(char* _ptrMTBname);
          void showMTBinfo(void);
   private:
          char MTBname[10];
          byte IdNo;
};
#endif

