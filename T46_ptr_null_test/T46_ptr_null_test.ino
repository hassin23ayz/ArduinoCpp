void doWorkOnA(int* ptr_a)
{
  ptr_a = NULL;
  Serial.println(*ptr_a);
}


void setup() 
{
  Serial.begin(9600);
  int a = 10;
  int* ptr_a = &a;
  Serial.println(a);
  Serial.println(*ptr_a);
  doWorkOnA(ptr_a);
  *ptr_a = 23; 
  Serial.println(*ptr_a);
}

void loop() 
{

}
