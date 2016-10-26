/*
 * @brief: polymorphic object is created using virtual function
 * here member function printType() of the base class Shape is declared as a virtual function
 * this virtual function is overrided in the Circle & Triangle Classes
 * now using Base Class type pointer overrided function can be called . this is called polymorphism 
 * The following code shows it
 */

/*
 * Circle class inherits Shape Class
 */

#include "Shape.h"
class Circle : public Shape
{
  public: 
          Circle()
          {
            Serial.println("creating a object of type Circle");   
          }

          ~Circle()
          {
            Serial.println("Destructing the Circle Type object created");
          }

          //overriding function
          void printType(void)
          {
            Serial.println("this is a Circle Class function");
          }
};

/*
 * Triangle class inherits Shape Class
 */
 
class Triangle : public Shape
{
  public: 
          Triangle()
          {
            Serial.println("creating a object of type Triangle");   
          }
          
          ~Triangle()
          {
            Serial.println("Destructing the Triangle Type object created");
          }
          
          //overriding function
          void printType(void)
          {
            Serial.println("this is a Triangle Class function");
          }
};

void setup() 
{
  Serial.begin(9600);
  Serial.print(F("before object creation Free SRAM: "));
  Serial.println(getFreeRam());
  
  Shape shpObj;
  Circle crlObj;
  Triangle trnObj;

  Serial.print(F("after object creation Free SRAM: "));
  Serial.println(getFreeRam());

  Shape* shpPtr1 = &shpObj;
  Shape* shpPtr2 = &crlObj;
  Shape* shpPtr3 = &trnObj;

  shpPtr1->printType();
  shpPtr2->printType();
  shpPtr3->printType();

  Serial.print(F("after calling the functions Free SRAM: "));
  Serial.println(getFreeRam());
}

void loop() 
{}

/*
 * @brief: this function returns the number of bytes free at SRAM
 */
int getFreeRam()
{
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}
