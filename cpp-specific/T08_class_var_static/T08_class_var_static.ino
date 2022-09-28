#include "MTB.h"

void setup() 
{
  //MTB::noOfMtb = 0;
  Serial.begin(9600);
  MTB myMtb0("uPland");
  MTB myMtb1("mongoose");
  MTB myMtb2("trek");
  
  myMtb0.showMTBinfo();   
  myMtb1.showMTBinfo();  
  myMtb2.showMTBinfo();
  
  MTB::noOfMtbsMade();
}

void loop() 
{
}
