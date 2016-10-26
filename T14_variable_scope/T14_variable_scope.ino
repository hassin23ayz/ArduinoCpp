void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i = 0;
  i =23;
  Task();
  Serial.println(i);  //i don't vanishes 
}

void Task()
{
  Serial.println("another Task"); 
}

