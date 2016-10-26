//array is never passed by value it's always passed by reference because C is intellegent enough

void setup() 
{
  Serial.begin(9600);
  uint8_t dataTX[13] = {1,3,10,12,31,20,15,23,59,59,0,0,1};

/*********** data printing *****************/
  uint8_t no_of_elements = sizeof(dataTX);  //no of bytes
  //uint8_t no_of_elements = sizeof(dataTX)/sizeof(dataTX[0]); //no of elements
  Serial.print("No of Elements :");
  Serial.println(no_of_elements);
  Serial.println("data elements are: ");
  for(byte i=0; i<no_of_elements; i++)
  {
    Serial.print(dataTX[i],DEC);
    Serial.print(',');
  }
  Serial.write('\n');

/*******************************************/  
  
  doZeroPad(dataTX,no_of_elements);
  //doZeroPad(dataTX,32);
}

void loop() 
{}

void doZeroPad(uint8_t arrTX[], uint8_t n)
{
  Serial.print("no of incoming elements = ");
  Serial.println(n,DEC);
  Serial.print("incoming data array is = ");
  for(byte i=0; i<n; i++)
  {
    Serial.print(arrTX[i],DEC);
    Serial.print(',');
  }
  Serial.print('\n');

  uint8_t blockSize = 16;
  
  if((n>=16)&&(n<=32))
    blockSize=32;
  else if ((n>=32)&&(n<=48))
    blockSize = 48;
  else if ((n>=48)&&(n<=64))
    blockSize = 64;    
  else
    blockSize = 16;
  Serial.print("block Size: ");
  Serial.println(blockSize);  
  
  uint8_t plain[blockSize];
  
  for(byte i=0; i<n; i++)
  {
    plain[i] = arrTX[i];
    Serial.print(arrTX[i],DEC);
    Serial.print('\t');
    Serial.println(plain[i],DEC);
  }
  for(byte i=n; i<blockSize; i++)
  {
    plain[i] = 0;
    Serial.println(plain[i],DEC);
  }

  Serial.println("After padding data elements are: ");
  for(byte i=0; i<blockSize; i++)
  {
    Serial.print(plain[i],DEC);
    Serial.print(',');
  }
  Serial.write('\n');   
}

