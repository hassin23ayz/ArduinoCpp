//coder: hassin ayaz
//this program shows why pointer is so much powerful 

#include <stdio.h>

#define ARR_LENGTH 10
byte v[ARR_LENGTH]={0,1,2,3,4,5,6,7,8,9};

void setup() {
Serial.begin(9600);
}

void loop() {
unsigned long dt;
Play_v_elements(v);
unsigned long t1=micros();
Print_v_elements(v);  //only array name is sent
dt=micros()-t1;
Serial.print("time taken in us:");
Serial.println(dt);
//Print_v_elements(v[ARR_LENGTH]);  //array is sent but will generate error
//Print_v_elements(v[]);  //array is sent but will generate error
//so only array name could be sent
t1=micros();
for(byte i=0; i<ARR_LENGTH; i++)
   Serial.println(v[i]);   //stack mechanism will happen here ie each value of the array will be stored in stack 
//Serial.println("printing at main loop is finished");
dt=micros()-t1;
Serial.print("time taken in us:");
Serial.println(dt);
Serial.flush();
exit(0);
}
void Play_v_elements(byte Arr[])
{
  for(byte i=0; i<ARR_LENGTH; i++)
     Arr[i]=(ARR_LENGTH-1)-i;
}
//void Print_v_elements(byte *ptrArr) //(1) memory location is got
void Print_v_elements(byte Arr[]) //(2) looks like array is recieved actually memory address is recieved
{
  for(byte i=0; i<ARR_LENGTH; i++)
    //Serial.println(*ptrArr++); //(1) memory address is being used & it gets incremented according to the scalar value
    Serial.println(Arr[i]);       //(2) actually memory address is being used 
                                  //stack mechanism wont happen as we are directly accessing the memmory locations of the array 
                                  // using pointer :)
    //Serial.println("Printing at function is completed");
}
//so we can say that actually array is reference type rather than value type 
/* it is beautiful in this way becz array was like value type then while sending the array(value type) 
to a function would require the stack mechanism to run and it would take so long time to process .. 
but as array is reference type we can directly access the memory locations of the array elements & play with them */

//if we use the (2) way code is more readable 

