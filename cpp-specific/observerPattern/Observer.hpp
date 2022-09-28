//observer
#pragma once

#include <vector>
#include "Subject.hpp"

class Subject;   //forward declaration 

//Observer
class Observer 
{ 
public: 
 Observer() {}; 
 ~Observer() {}; 
 virtual void Update(Subject* theChangeSubject) = 0; 
}; 