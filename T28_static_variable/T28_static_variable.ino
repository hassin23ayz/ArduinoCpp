//static variable wont get initialized wahen each time called 

void setup() 
{
  Serial.begin(9600);
  testFunction1(6);
  testFunction1(7);
  testFunction1(8);
}

void loop() 
{
  //testFunction2();
  delay(2000);
}

void testFunction1(int i)
{
  static int valueToBePrinted = i; //initialzed by i 
  Serial.println(valueToBePrinted, DEC);

  if(valueToBePrinted != i)
    Serial.println("value is not same");
}

void testFunction2()
{
  static int i = 0;
  Serial.println(i,DEC);
  i++;
}

