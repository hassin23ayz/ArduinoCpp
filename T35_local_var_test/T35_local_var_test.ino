/*this sketch shows that local variable testVar & testvar2 wont retain its value between each loop
  so you can either make them global or static if you need to
  & secondly the variable is allocated once i.e. it does note create memory slot at each time 
*/

unsigned int testVar3 = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  //this variable is initialized 
  unsigned int testVar = 0; 
  Serial.print("variable initialized with 0 = ");
  Serial.println(testVar);
  testVar++;

  //variable not initialized 
  unsigned int testVar2;
  Serial.print("variable not initialized = ");
  Serial.println(testVar2);
  testVar2++;

  //gloabal variable
  Serial.print("gloabal variable = ");
  Serial.println(testVar3);
  testVar3++;

  //static variable
  static unsigned int testVar4 = 0;
  Serial.print("static variable = ");
  Serial.println(testVar4);
  testVar4++;  

  Serial.println("-------------------------------------");
  Serial.print("free ram = ");
  Serial.println(freeRam());
  Serial.println("-------------------------------------");
  
  delay(1000);
}

int freeRam()
{
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}


