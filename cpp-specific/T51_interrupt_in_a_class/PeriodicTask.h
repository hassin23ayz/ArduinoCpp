#ifndef PERIODIC_TASK_H_     //tells compiler to compile this class only once 
#define PERIODIC_TASK_H_

#include <Arduino.h>

class PeriodicTask
{
  public:
  
    PeriodicTask();
    ~PeriodicTask();  
    void init(unsigned long ms,  void (*ptrfunc)(void));   //input in millisecond , pass the function of the pointer you want to be called back 
    void sTart(void);
    void sTop(void);
    void overfLow(void);

  private:
    unsigned int tcnt2;
    unsigned long msecs;
    unsigned long count;

    void (*callBackFunc)(void);   //declares a function pointer
};

#endif
