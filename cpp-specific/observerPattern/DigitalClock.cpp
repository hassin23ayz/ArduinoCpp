#include "DigitalClock.hpp"
#include <iostream>
#include <string.h>

DigitalClock::DigitalClock (ClockTimer* s) 
{ 
   _subject = s; 
   _subject->Attach(this); 
}

DigitalClock::~DigitalClock () 
{
	_subject->Detach(this); 
}

void DigitalClock::Update(Subject* theChangedSubject) 
{ 
 if(theChangedSubject == _subject) 
   {
   	Draw();
   } 
} 

void DigitalClock::Draw () 
{ 
 cout << "Digital time is " << _subject->GetTime() << endl;           
}