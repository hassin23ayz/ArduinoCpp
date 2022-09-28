//Subject
#pragma once

#include "Observer.hpp"
#include <vector>
using namespace std ; 

class Observer;    //forward declaration
class Subject 
{ 
public: 
 Subject() {}; 
 virtual ~Subject() {}; 
 virtual void Attach(Observer*); 
 virtual void Detach(Observer*); 
 virtual void Notify();  
private: 
 vector<Observer*> _observers; 
}; 
