#include "PeriodicTask.h"

PeriodicTask tsk;

void updateTask(void)
{
  Serial.println(F("UpdateTask() called by PeriodicTask Class"));
  analogWrite(10,128);
}

void setup() 
{
  Serial.begin(9600);
  Serial.println(F("This Class uses Timer2 to call a user given task periodically , No need to Poll"));

  tsk.init(3000, &updateTask);
  tsk.sTart();
}

void loop() 
{}

