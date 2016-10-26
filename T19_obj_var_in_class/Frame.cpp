#include "Frame.h"

Frame::Frame(char* ptrType)
{
  strcpy(type,ptrType);
}

void Frame::printFrameType(void)
{
  Serial.print("Frame type is: ");
  Serial.println(type);
}

