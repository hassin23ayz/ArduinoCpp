#ifndef _SCH51_H
#define _SCH51_H

#include <Arduino.h> 
#define ERROR_SCH_TOO_MANY_TASKS 2
#define ERROR_SCH_CANNOT_DELETE_TASK 3
#define RETURN_ERROR 0
#define RETURN_NORMAL 1

//this is a scheduler data Structure 
typedef struct SCHdata        // Total memory per task is 7 bytes
{
  void (*pTask)(void);     // function Pointer is declared (must be a 'void (void)' function)  
  word Delay;                // Delay (ticks) until the function will (next) be run
  word Period;               // Interval (ticks) between subsequent runs.  
  byte RunMe;                // Incremented (by scheduler) when task is due to execute
} sTask; 

#ifdef __cplusplus
extern "C" {
#endif

void SCH_Init_T2(void);       //initialixzation function
void SCH_Start(void);

void  SCH_Dispatch_Tasks(void);          //dispatcher function that causes tasks to be executed when they are due to run
byte  SCH_Add_Task(void (*_pTask)(void) , const word, const word);   //function for adding tasks
byte  SCH_Delete_Task(const byte);

#ifdef __cplusplus
}
#endif

#define SCH_MAX_TASKS 2      //number of tasks

#endif

