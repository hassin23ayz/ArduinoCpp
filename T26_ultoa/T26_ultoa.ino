void setup() 
{
  Serial.begin(9600);
  char strValues[24];
  uint32_t tmpInt;
  char tmpStr[7];
  
  tmpInt = 0;
  memset(tmpStr, '\0' , 7); 
  tmpInt = (uint32_t)(230.7*10);
  ultoa(tmpInt,tmpStr,10);
  strcpy(strValues,tmpStr);
  Serial.println(tmpStr);

  tmpInt = 0;
  memset(tmpStr, '\0' , 7); 
  tmpInt = (uint32_t)(9999.9*10);
  ultoa(tmpInt,tmpStr,10);
  strcat(strValues,tmpStr);
  Serial.println(tmpStr);

  tmpInt = 0;
  memset(tmpStr, '\0' , 7); 
  tmpInt = (uint32_t)(0.8*100);
  ultoa(tmpInt,tmpStr,10);
  strcat(strValues,tmpStr);
  Serial.println(tmpStr);

  tmpInt = 0;
  memset(tmpStr, '\0' , 7); 
  tmpInt = (uint32_t)(99999.87*100);
  Serial.println(tmpInt);
  ultoa(tmpInt,tmpStr,10);
  strcat(strValues,tmpStr);
  Serial.println(tmpStr);

  tmpInt = 0;
  memset(tmpStr, '\0' , 7); 
  tmpInt = 1;
  ultoa(tmpInt,tmpStr,10);
  strcat(strValues,tmpStr);
  Serial.println(tmpStr);  

  tmpInt = 0;
  memset(tmpStr, '\0' , 7); 
  tmpInt = 2;
  ultoa(tmpInt,tmpStr,10);
  strcat(strValues,tmpStr);
  Serial.println(tmpStr);  

  tmpInt = 0;
  memset(tmpStr, '\0' , 7); 
  tmpInt = 456;
  ultoa(tmpInt,tmpStr,10);
  strcat(strValues,tmpStr);
  Serial.println(tmpStr); 

  Serial.println(strValues);

}

void loop() 
{}
