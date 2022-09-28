#ifndef __MSGMANAGER__
#define __MSGMANAGER__

#include "CallBackInterface.h"
#include "MQTT.h"
#include <Arduino.h>

class MsgManager : public CallBackInterface   //callee class
{
  public:
        MsgManager()
        {
          mqttObj.connectForCallback(this);
        }
        void operate(void)
        {
          Serial.println("MsgMng type obj: hi i am operating now going to give mqtt obj a task");
          mqttObj.doTask();
        }
      
        void filter(void) //function which will be called from mqtt object
        {
          Serial.println("MsgMng type obj: my slave mqtt obj has asked for filtering");
          Serial.println("MsgMng type obj: now i am going to filter");
        }
  private:
        MQTT mqttObj;
};

#endif
