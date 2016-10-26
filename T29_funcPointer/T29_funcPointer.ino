void kick(void)
{
  Serial.println("Kick the ball");
}

void extraTime(int _t)
{
  Serial.print("extra time left is: ");
  Serial.println(_t);
}

void takeFuncPtr(void (*_ptrFunc)(void))
{
  (*_ptrFunc)();
}
void setup() 
{
  Serial.begin(9600);
  void (*ptrFunc)(void);  //declares "ptrFunc" to be a pointer to a function 
                          //which's parameter is void and return type is void
  ptrFunc = &kick;        //the function pointer holds the address of the kick() function
  (*ptrFunc)();           //you can call either the way using function pointer 
  ptrFunc();

  /****************************************************************************/
  int timeleft = 3;

  void (*ptrFunc2)(int _t);  //declares "ptrFunc2" to be a pointer to a function 
                          //which's parameter is int and return type is void
  ptrFunc2 = &extraTime;   //the function pointer holds the address of the extraTime() function
  (*ptrFunc2)(timeleft);   //you can call either the way using function pointer 
  ptrFunc2(timeleft);   
  /***************************************************************************/

  takeFuncPtr(ptrFunc);                      
}

void loop() 
{

}
