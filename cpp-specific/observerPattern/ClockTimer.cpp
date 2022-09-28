#include "ClockTimer.hpp"

#include <time.h>
#include <sys/types.h>
#include <sys/timeb.h>
#include <string.h>
#include <iostream>
#include <cstring>
#include <cstdlib>

#include <string>
using std::string;

ClockTimer::ClockTimer() {}
ClockTimer::~ClockTimer(){} 

void ClockTimer::Tick() 
{ 
   //Obtain operating system-style time.

   time_t rawtime;
   struct tm * timeinfo;
  
   time(&rawtime);
   timeinfo = localtime(&rawtime);
   
   strftime(tmpbuf, 128, "%I:%M%p.", timeinfo);  
   Notify(); 
}

std::string ClockTimer::GetTime() 
{ 
	return string(tmpbuf);
}