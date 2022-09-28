/**
 * @file  T13_obj_classes.ino
 * @brief this sketch creates a ball. the ball will bounce and a led will blink  
 * 
 * @author  Hassin Ayaz 
 * @date 08/13/2016
 */

#include "ball.h"

//this will create the ball type object
Ball b(13,1000);

void setup() 
{
  //this will initialize the UART pins to act as Serial Transmission and recieve
  Serial.begin(9600);
  Serial.println("Ball object created");
}

void loop() 
{
 //Now the ball will bounce by blinking the LED 
 Serial.println("Ball will bounce i.e Led will Blink");
 b.bounce();
}
