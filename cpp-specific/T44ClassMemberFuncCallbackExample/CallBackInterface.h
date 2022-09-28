#ifndef __CALLBACKINTERFACE__
#define __CALLBACKINTERFACE__

class CallBackInterface 
{
  public:
        CallBackInterface()
        {}
        virtual void filter(void) = 0;
};

#endif

