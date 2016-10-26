#ifndef _CUSTOMLCD_H      //tells compiler to compile this class only once 
#define _CUSTOMLCD_H 

#include <Arduino.h>
#include <LiquidCrystal.h>

class CustomLCD
{
   public:
          CustomLCD();
          void showSomething(void);
   private:
          LiquidCrystal lcd;
};
#endif
