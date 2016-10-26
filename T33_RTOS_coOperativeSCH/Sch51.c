#include "Sch51.h"

byte errorCode;
sTask SCH_tasks_G[SCH_MAX_TASKS];  // The array of tasks
static void SCH_Go_To_Sleep(void);

void SCH_Dispatch_Tasks(void)      //When a task (function)is due to run, SCH_Dispatch_Tasks() will run it. 
                                   //This function must be called (repeatedly) from the main loop.
{
  byte Index;  
  for(Index = 0; Index < SCH_MAX_TASKS; Index++)   // Dispatches (runs) the next task (if one is ready)
  {
    if (SCH_tasks_G[Index].RunMe > 0) 
    {
       (*SCH_tasks_G[Index].pTask)();              // Run the task
       SCH_tasks_G[Index].RunMe -= 1;              // Reset / reduce RunMe flag Periodic tasks will automatically run again

       if (SCH_tasks_G[Index].Period == 0)         // - if this is a 'one shot' task, remove it from the array
       {
        SCH_Delete_Task(Index);
       }
    }
  }
  SCH_Go_To_Sleep();                               // The scheduler enters idle mode at this point 
}

byte SCH_Add_Task(void (*_pTask)(void), const word DELAY, const word PERIOD)    
{
   byte Index = 0;
   while ((SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS))  // First find a gap in the array (if there is one)
      {
      Index++;
      } 
       
   if (Index == SCH_MAX_TASKS)  // Have we reached the end of the list?  
      {
      errorCode = ERROR_SCH_TOO_MANY_TASKS;  // Task list is full Set the global error variable      
      return SCH_MAX_TASKS;                        
      }
   SCH_tasks_G[Index].pTask  = _pTask;       // If we're here, there is a space in the task array
   SCH_tasks_G[Index].Delay  = DELAY;
   SCH_tasks_G[Index].Period = PERIOD;

   SCH_tasks_G[Index].RunMe  = 0;

   return Index; // return position of task (to allow later deletion)
}

byte SCH_Delete_Task(const byte TASK_INDEX) // Removes a task from the scheduler.
{
   byte Return_code;

   if (SCH_tasks_G[TASK_INDEX].pTask == 0)   // No task at this location...
      {
      errorCode = ERROR_SCH_CANNOT_DELETE_TASK;  // Set the global error variable
      Return_code = RETURN_ERROR;        // ...also return an error code
      }
   else
      {
      Return_code = RETURN_NORMAL;
      }      
   
   SCH_tasks_G[TASK_INDEX].pTask   = 0x0000;
   SCH_tasks_G[TASK_INDEX].Delay   = 0;
   SCH_tasks_G[TASK_INDEX].Period  = 0;

   SCH_tasks_G[TASK_INDEX].RunMe   = 0;

   return Return_code;       // return status
}

/*
  This scheduler enters 'idle mode' between clock ticks
  to save power.  The next clock tick will return the processor
  to the normal operating state. */
void SCH_Go_To_Sleep()
{}

//initialization function prepares the scheduler array , error codes 

void SCH_Init_T2(void) 
{
   byte i;
   for (i = 0; i < SCH_MAX_TASKS; i++) 
   {
      SCH_Delete_Task(i);
   }
                           
   TCCR2A = 0x00;                  //clearing the registers because at wiring.c these were used for pwm 
   TCCR2B = 0x00;
   TCNT2 = 0x00;
  
   TCCR2A |= (1<<WGM21);           //CTC mode
   TCCR2B |= (1<<CS20)|(1<<CS22);  //prescalar is 128
   OCR2A = 125;                    //Output compare register loaded
   TIMSK2 |= (1<<OCIE2A);          //Timer/Counter2 Output Compare Match A Interrupt Enabled
}

/*  Starts the scheduler, by enabling interrupts.

  NOTE: Usually called after all regular tasks are added,
  to keep the tasks synchronised.

  NOTE: ONLY THE SCHEDULER INTERRUPT SHOULD BE ENABLED!!! 
 
-*------------------------------------------------------------------*/
void SCH_Start(void) 
{
  sei();
}

ISR(TIMER2_COMPA_vect)   
{
   byte Index;

   //TF2 = 0; // Clear flag 
 
   // NOTE: calculations are in *TICKS* (not milliseconds)
   for (Index = 0; Index < SCH_MAX_TASKS; Index++)
      {
      // Check if there is a task at this location
      if (SCH_tasks_G[Index].pTask)
         {
         if (SCH_tasks_G[Index].Delay == 0)
            {
            // The task is due to run
            SCH_tasks_G[Index].RunMe = 1;  // Set the run flag

            if (SCH_tasks_G[Index].Period)
               {
               // Schedule periodic tasks to run again
               SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
               }
            }
         else
            {
            // Not yet ready to run: just decrement the delay 
            SCH_tasks_G[Index].Delay -= 1;
            }
         }         
      }
}   


