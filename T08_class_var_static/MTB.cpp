#include "MTB.h"

MTB::MTB(char* _ptrMTBname)
{
  strcpy(MTBname,_ptrMTBname);
  IdNo = noOfMtb;
  noOfMtb++;
}

byte MTB::noOfMtb = 0; //you just dont say its static here its gonna kill you as you have told its static in header file

void MTB::showMTBinfo()
{
  Serial.print("MTB name: ");
  Serial.println(MTBname);
  Serial.print("This Id no is: ");
  Serial.println(IdNo);
}

void MTB::noOfMtbsMade(void) //you just dont say its static here its gonna kill you as you have told its static in header file
{
  Serial.print("you have made ");
  Serial.print(noOfMtb,DEC);
  Serial.println("  mountain bikes using 3D printer :D ");
}

