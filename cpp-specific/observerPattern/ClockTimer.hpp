// a ConcreteSubject
#pragma once

#include "Subject.hpp"
#include <string>
using std::string;

class ClockTimer : public Subject 
{ 
public: 
 ClockTimer();
 ~ClockTimer(); 
 std::string GetTime(); 
 void Tick();   
private: 
 char tmpbuf[128]; 
};


