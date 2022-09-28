#include "CustomLCD.h"

CustomLCD::CustomLCD():lcd(12, 11, 5, 4, 3, 2)   //here private variable lcd object gets auto initilized with pins                                               
{
  lcd.begin(16, 2);
}

void CustomLCD::showSomething(void)
{
  lcd.print("hello, world!");  
}

