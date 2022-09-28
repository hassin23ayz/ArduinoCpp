// observer pattern example
#include "DigitalClock.hpp"
#include "ClockTimer.hpp"

int main(void) 
{
 //create a concrete subject
 ClockTimer timer;
 //create a concrete observer 
 //attaching the subject to be observed
 DigitalClock digitalClock(&timer); 
 
 //run the operation of the subject
 //it will automatically update it's observers
 timer.Tick();

 return 0; 
}
