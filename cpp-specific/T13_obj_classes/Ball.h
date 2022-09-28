/**
 * @file  Ball.h
 * @brief This is the Ball library's header file.
 * @author  Hassin Ayaz 
 * @date 08/13/2016
 */


#ifndef _BALL_H      //tells compiler to compile this class only once 
#define _BALL_H

#include <Arduino.h>

class Ball
{
   public:
          Ball(byte _pin, unsigned long int _bounceTime);
          void bounce(void);
          void turnOnLed(void);
          void turnOffLed(void);
   private:
          unsigned long int bounceTime; /*!< variable which will contain the delay time */
          byte pin;                     /*!< variable which will hold the arduino pin number */
};
#endif
