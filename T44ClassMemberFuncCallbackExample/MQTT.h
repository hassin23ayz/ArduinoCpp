#ifndef __MQTT__
#define __MQTT__

#include "CallBackInterface.h"
#include <Arduino.h>

class MQTT //caller class
{
  public:
        MQTT()
        {}
        void connectForCallback(CallBackInterface* ptrMsgMng)
        {
          myMsgMng = ptrMsgMng;
        }
        void doTask(void)
        {
          Serial.println("mqtt type obj: i am mqtt doing mytasks taking bytes, next filter is needed");
          //now going to call back my master that i have recieved bytes
          myMsgMng->filter();
        }
   private:
        CallBackInterface* myMsgMng;
};

#endif
