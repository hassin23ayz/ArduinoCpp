/****** this example shows how the levelsensor class can be used to know a tank's state *****/

#include <LevelSensor.h>

LevelSensor upperTank(A2,A3);
void setup() {
 Serial.begin(9600);
}

void loop() {
  Serial.print("Upper Tank state: ");
  byte uT = upperTank.isTankFilled();
  if(uT==1){Serial.println("Filled");}
  if(uT==0){Serial.println("Empty");}
  if(uT==255){Serial.println("Sensor is not OK");}
}
