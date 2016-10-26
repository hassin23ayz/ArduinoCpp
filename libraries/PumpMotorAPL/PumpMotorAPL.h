/*
  PumpMotorAPL.h - Library for controlling both WASa & ROOF motors 
  header file has all the definitions
*/

#ifndef PumpMotorAPL_h      
#define PumpMotorAPL_h

#include "Arduino.h"   

//water level sensor configuration
#define ROOF_FL_SENS_1 A2
#define ROOF_FL_SENS_2 A3
#define RSV_FL_SENS_1 A4
#define RSV_FL_SENS_2 A5

//Motor pin configuration
#define UP_M_ON 9
#define UP_M_OFF 10
#define W_M_ON 11
#define W_M_OFF 12

//buzzer pin configuration
#define BUZZER 4

//Macros for decision making
#define RSV_FULL ((digitalRead(RSV_FL_SENS_1)==HIGH) && (digitalRead(RSV_FL_SENS_2)==LOW))
#define RSV_EMPTY ((digitalRead(RSV_FL_SENS_1)==LOW) && (digitalRead(RSV_FL_SENS_2)==HIGH))
#define RSV_SENS_ERR (((digitalRead(RSV_FL_SENS_1)==HIGH) && (digitalRead(RSV_FL_SENS_2)==HIGH))||((digitalRead(RSV_FL_SENS_1)==LOW) && (digitalRead(RSV_FL_SENS_2)==LOW)))

#define ROOF_FULL ((digitalRead(ROOF_FL_SENS_1)==HIGH) && (digitalRead(ROOF_FL_SENS_2)==LOW))
#define ROOF_EMPTY ((digitalRead(ROOF_FL_SENS_1)==LOW) && (digitalRead(ROOF_FL_SENS_2)==HIGH))
#define ROOF_SENS_ERR (((digitalRead(ROOF_FL_SENS_1)==HIGH) && (digitalRead(ROOF_FL_SENS_2)==HIGH))||((digitalRead(ROOF_FL_SENS_1)==LOW) && (digitalRead(ROOF_FL_SENS_2)==LOW)))

#define CONS 4.9
#define RARE 6.9
#define RURAL 8
#define VILL 10
#define GENERAL 12
#define TOWN 16
#define CITY 17
#define RES 25
#define INDUS 28

class PumpMotorAPL      //have to create a object of this type to use the things that this class offers
{
  public:               //public parts are here
    PumpMotorAPL(void);
    void monitorLevel(void);                         //public function which will sense the level sensors & act accordingly 
    void monitorCurrent(byte hp,float current);    //public function which will see if overcurrent flows and act accordingly 
    //Morse(int pin);
    //void dot();
    //void dash();
  private:              //private parts are here 
    //byte _hp;
	//float current;
};
#endif