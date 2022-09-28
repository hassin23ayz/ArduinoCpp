void setup() 
{
  /************************** pointer ***********************************/
  Serial.begin(9600);
  int a;
  Serial.println(a);  //print the initial value of a
  int* ptr_a;
  ptr_a = &a;
  Serial.println((uint16_t)ptr_a); //print the memory address stored by the pointer variable
  Serial.println(*ptr_a);
  a = 10 ; 
  Serial.println(a);
  Serial.println(*ptr_a);
  *ptr_a = 23;
  Serial.println(a);
  Serial.println(*ptr_a);

  Serial.println("************************************************");
  /************************** reference ***********************************/

  int b = 9; 
  Serial.println(b);
  int& ref_b = b;
  Serial.println(ref_b);
  b = 10;
  Serial.println(b);
  Serial.println(ref_b);
  ref_b = 23;
  Serial.println(b);
  Serial.println(ref_b);
}

void loop()
{}
