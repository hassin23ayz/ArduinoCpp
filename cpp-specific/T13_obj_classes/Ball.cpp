/**
 * @file  Ball.cpp
 * @mainpage The Ball Library
 * @brief This is the Ball class which is a blueprint to create a ball.
 * 
 * @section intro_sec Introduction
 * A small Library to create A ball which is imitated by blinking a LED
 * 
 * @note ![my Blog] http://whileinthisloop.blogspot.com/2016/04/c-in-arduino-t13-classes-and-objects.html
 * 
 * @subsection step1 License
 * this work is under ![Creative Common License] (https://creativecommons.org/licenses/by/4.0/)
 * 
 * @subsection step2 Using the Library
 * usage: in order to use this library
 * 
 *      1. you need to associate a pin and attach a led with it
 *      
 *      2. you need to set the pin no & delay time in the constructor
 *      
 * @author  Hassin Ayaz 
 * @date 08/13/2016
 */


#include "ball.h"

/**
 * Ball() constructor takes blinking pin & bounce type information to create the ball
 * @author Hassin Ayaz
 * @param _pin the Pin which will on/off to blink the Led
 * @param _bounceTime the time by which Led will on and again off  
 * @date 08/13/2016
 */
Ball::Ball(byte _pin, unsigned long int _bounceTime)
{
  bounceTime=_bounceTime;
  pin = _pin;
  //this will set the pin as output  
  pinMode(pin,OUTPUT);
}

/**
 * This is actual Bounce method. Basically a Led will turn on & off
 * @author Hassin Ayaz
 * @param void  
 * @date 08/13/2016
 */

void Ball::bounce(void)
{
  turnOnLed();
  turnOffLed();
}

/**
 * This method will turn on Led
 * @author Hassin Ayaz
 * @param void  
 * @date 08/13/2016
 */

void Ball::turnOnLed(void)
{
  //this will set the pin 
  digitalWrite(pin,HIGH);
  //pin will be high by this delay
  delay(bounceTime);
}
/**
 * This method will turn off Led
 * @author Hassin Ayaz
 * @param void  
 * @date 08/13/2016
 */

void Ball::turnOffLed(void)
{
  //this will clear the pin
  digitalWrite(pin,LOW);
  //pin will be low by this delay
  delay(bounceTime);
}

