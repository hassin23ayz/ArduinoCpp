//RTOS - simple co operative scheduler 

#include "LED_flas.h"
#include "Sch51.h"

void setup() 
{
  Serial.begin(9600);
  SCH_Init_T2();                             // Set up the scheduler using TIMER2 for 1 ms tick
  LED_Flash_Init(13);                        // Prepare for the 'Flash_LED' task
  SCH_Add_Task(LED_Flash_Update, 0, 1000);   //(on for 1000 ticks, off for 1000 ticks) timings are in ticks
  SCH_Add_Task(control,5000,0); 
  SCH_Start();                               //start the scheduler 
}

void control(void)
{
  Serial.println("Controlling...");
  delay(1000);
}


void loop() 
{
  SCH_Dispatch_Tasks(); 
}
