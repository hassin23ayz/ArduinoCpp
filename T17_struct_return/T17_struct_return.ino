//this example 

#include "Enum_Struct.h"

struct GSMDATA GSMTask();

void setup() 
{
  Serial.begin(9600);
  struct GSMDATA myData;
  myData = GSMTask();

  Serial.print("Reason: ");
  Serial.println(myData.gsmRetReason);
  Serial.print("Returned GSM data: ");
  for (byte i=0; i<8; i++)
  {
    Serial.print(myData.gsmRetData[i]);
    Serial.print("\t");
  }
}

struct GSMDATA GSMTask(void)
{
  struct GSMDATA gsmData;
  gsmData.gsmRetReason = PWR_F;
  byte temp_array[8] = {0,1,2,3,4,5,6,7};
  memcpy(gsmData.gsmRetData,temp_array,8); 
  return gsmData;
}

void loop() 
{}
