#include "MTB.h"

MTB::MTB()
{
  t = new Tyre(26);
  f = new Frame("Aluminium Alloy");
}

void MTB::showSpec()
{
  f->printFrameType();
  t->printTyreSize();
}


