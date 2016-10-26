#include <arduino.h>
extern int i;  //declaration of a variable named s which is defined in another source code
void Print(void) //definition
{
  if(i==0)
  {
    Serial.begin(9600);
  }
  Serial.println(i);
  i++;
  delay(2000);
}
