#include "Shape.h"

Shape::Shape()
{
  Serial.println("creating a object of type Shape");   
}

Shape::~Shape()
{
  Serial.println("Destructing the Shape Type object created");
}
//the virtual function which will serve polymorphism 
void Shape::printType(void)                       
{
  Serial.println("this is a Shape Class function");
}
