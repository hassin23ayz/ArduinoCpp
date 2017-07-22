/*
 * This Class uses Timer 2 to call a user given task periodically 
 * No polling is needed 
 */

#include "PeriodicTask.h"

static PeriodicTask* pt;
PeriodicTask::PeriodicTask()
{
  pt = this;
  tcnt2 = 0;
  msecs = 0;
  count = 0;
}

PeriodicTask::~PeriodicTask()
{
  Serial.println(F("PeriodicTask destructor called"));
}

void PeriodicTask::init(unsigned long ms, void (*ptrFunc(void)) )  //pass the function of the pointer you want to be called back 
{
  callBackFunc = ptrFunc;
  float prescaler = 0.0;
  
  if (ms == 0)
    msecs = 1;
  else
    msecs = ms;
   
  TIMSK2 &= ~(1<<TOIE2);
  TCCR2A &= ~((1<<WGM21) | (1<<WGM20));
  TCCR2B &= ~(1<<WGM22);
  ASSR &= ~(1<<AS2);
  TIMSK2 &= ~(1<<OCIE2A);
  
  TCCR2B |= (1<<CS22);
  TCCR2B &= ~((1<<CS21) | (1<<CS20));
  prescaler = 64.0;

  tcnt2 = 256 - (int)(((float)F_CPU * 0.001)/ prescaler);  //starting value of TCNT2 caluculation
}

void PeriodicTask::sTart(void)
{
  count = 0;
  
  TCNT2 = tcnt2;               //starting value of TCNT2
  TIMSK2 |= (1<<TOIE2);
}

void PeriodicTask::sTop(void)
{
  TIMSK2 &= ~(1<<TOIE2);
}

void PeriodicTask::overfLow(void)
{   
  TCNT2 = tcnt2;                //reload starting value of TCNT2
  count++;
  
  if (count >= msecs) 
  {
    //Serial.println(F("user time passed"));
    count = 0;
    callBackFunc();
  }
}

ISR(TIMER2_OVF_vect)
{
  pt -> overfLow();  
}


