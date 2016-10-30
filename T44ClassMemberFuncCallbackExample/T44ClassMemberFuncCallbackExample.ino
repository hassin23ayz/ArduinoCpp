//this sketch shows how to callback a member function of a class from another object using polyporphism via abstract class

#include "MsgManager.h"

MsgManager* msgMngObj; //callee

void setup() 
{
  Serial.begin(9600);
  msgMngObj = new MsgManager();
  msgMngObj->operate();
}

void loop() 
{}

