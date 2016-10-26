#include <FEEPROM.h>
#include <EEPROM.h>

FEEPROM whF(10,310);  //4 bytes for 1 variable 75*4=300 bytes 
void setup() 
{
  Serial.begin(9600); 
  while(1)
     {
     float t = millis()+0.23;
     whF.writeCircularFEEPROM(t);
     delay(100);
     Serial.println(t);
     if(Serial.available()>0)
       {
        if(Serial.read()=='a')
          break; 
       }  
     }
  float max_t = whF.readMaxFEEPROM();
  Serial.println("Maximum Value:");
  Serial.println(max_t);      
}

void loop() 
{ 
}

