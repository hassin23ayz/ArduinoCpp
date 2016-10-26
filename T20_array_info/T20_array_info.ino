int data[8] = {0,1,2,3,4,5,6,7};

void setup() 
{
  Serial.begin(9600);
  arrayInfo();
  
  byte data2[6] = {0,1,2,3,4,5};
  int n = *(&data2 + 1) - data2;
  Serial.print("Number of bytes in your array is : ");
  Serial.println(n);
  Serial.print("Number of elements in your array is : ");
  Serial.println(n/sizeof(data2[0]));     
}

void loop() 
{}

void arrayInfo()
{
  Serial.print("Number of bytes in your array is : ");
  Serial.println(sizeof(data));

  Serial.print("Number of elements in your array is : ");
  Serial.println(sizeof(data)/sizeof(data[0]));  
}


