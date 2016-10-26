#include <arduino.h> 

typedef enum GSM_REASON
{
  PWR_F,
  PARA_F,
  PORT_F,
  SETUP_F,
  ACTION_F,
  DATA_F,
  CLOSE_F
};

struct GSMDATA{
  enum GSM_REASON gsmRetReason;
  byte gsmRetData[8];
};
