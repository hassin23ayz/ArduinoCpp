//string to int
void setup() 
{
  Serial.begin(9600);
  char str[5] = "1234";
  Serial.print("String is : ");
  Serial.println(str);
  int i = atoi(str);
  Serial.print("integer value is : ");
  Serial.println(i,DEC);
}

void loop() 
{
  
}
