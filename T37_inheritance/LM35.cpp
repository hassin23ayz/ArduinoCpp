#include "LM35.h"

LM35::LM35()                                             
{}

float LM35::readCelsius(void)
{
  float mv = readmv();
  float cls = mv/10.0;
  return cls;
}

float LM35::readFahrenheit(void)
{
  float cls = readCelsius();
  float fhr = (cls*9)/5 + 32;
  return fhr;
}
