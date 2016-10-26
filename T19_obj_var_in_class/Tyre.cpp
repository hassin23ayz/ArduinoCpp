#include "Tyre.h"

Tyre::Tyre(byte _size)
{
  tsize = _size;
}

void Tyre::printTyreSize(void)
{
  Serial.print("Tyre Size is: ");
  Serial.println(tsize,DEC);
}

