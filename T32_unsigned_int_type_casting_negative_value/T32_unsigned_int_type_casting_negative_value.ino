void setup() 
{
  Serial.begin(9600);
  Serial.println((unsigned long)(60-80)); //type casting
  Serial.println(abs(60-80)); //type casting
}

void loop()
{
  delay(3000);
  exit(EXIT_SUCCESS);
}
