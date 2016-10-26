/**** this sketch shows the function implementation of the Relay class ****/

#include <Relay.h>

#define FILL 1
#define EMPTY 0

Relay roofPump(9);   //arduino pin no 9 connected to the relay
void setup() {
  
  Serial.begin(9600);       //for debugging 
}

void loop() {
  float measuredCurrent = 2.34;
  float cutoffCurrent = 4.00;
  
  boolean lowertank = EMPTY;
  boolean uppertank = FILL;  
  
  roofPump.OnOffuponCurrent(measuredCurrent,cutoffCurrent);
  if(roofPump.GetRelayState())
    Serial.println("Relay is turen ON");
  else
    Serial.println("Relay is turen OFF");
  delay(2000);  
  
  roofPump.OnOffuponTankLevels(lowertank,uppertank);
  if(roofPump.GetRelayState())
    Serial.println("Relay is turen ON");
  else
    Serial.println("Relay is turen OFF"); 
  delay(2000);   
}
