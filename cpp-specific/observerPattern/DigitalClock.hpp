// a ConcreteObserver
#pragma once

#include "Observer.hpp"
#include "ClockTimer.hpp"

class DigitalClock: public Observer 
{ 
public: 
 DigitalClock(ClockTimer* );  
 ~DigitalClock();   
  void Update(Subject* );   
  void Draw();     
private: 
 ClockTimer* _subject;  
};

