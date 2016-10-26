//all the functions are defined in the header file .cpp file have the constructor the wrapped up class is in the header file
 
#include "FEEPROM.h"   // access to the definitions of the hmorse header file

FEEPROM::FEEPROM(word sA, word eA)  //constructor when a object of this type is created this constructor is called 
{
  startAdd = sA;
  endAdd = eA;
}

void FEEPROM::clearAllFEEPROM(void) //this function clears all the values in the eeprom block
{
  for(word i=0; i<=endAdd; i+=4)   
     {
     EEPROM.put(i,0);  
     } 
}

void FEEPROM::writeCircularFEEPROM(float f)  //this function will write values in a circular buffer way
{
  static word add = startAdd;
  EEPROM.put(add,f);
  add+=4;
  if(add>endAdd)
     add=startAdd;   
}

float FEEPROM::readMaxFEEPROM(void)          //returns max value of a block
{
 static float maxValue=0.0;
 EEPROM.get(startAdd,maxValue);
 for(word i=startAdd; i<=endAdd; i+=4)
	{
	  float tmp;
	  EEPROM.get(i,tmp);
	  maxValue=max(tmp,maxValue);
	}
 return maxValue;  
}


 