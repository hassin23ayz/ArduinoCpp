#include "LED_flas.h"

static byte ledState;
byte ledPin;

void LED_Flash_Init(byte _pin)
{
  ledPin = _pin;
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin,LOW); 
  ledState = 0;
}
   
void LED_Flash_Update(void)
{
  // Change the LED from OFF to ON (or vice versa)
  if (ledState == 1)
     {
       digitalWrite(ledPin,LOW);
       ledState = 0;
     }
  else
     {
       digitalWrite(ledPin,HIGH);
       ledState = 1;
     }
}
