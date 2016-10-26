void setup() 
{
  double _vRms = 220.4;
  double _KW = 56.1;
  double _pf = 0.83;
  double _KWhr = 345.78;
  uint8_t tariff = 1;
  uint8_t relay = 1;
  uint16_t sumMeter = 456;
  
  Serial.begin(9600);
  char strDAT[51];
  memset(strDAT, '\0' , 51);
  strcpy(strDAT,"0010DAT");
  strcat(strDAT,"10132015204103");
  strcat(strDAT,"AYZ0");

  padDvalueString(strDAT,_vRms, 10, 4);
  padDvalueString(strDAT,_KW, 10, 5);
  padDvalueString(strDAT,_pf, 100, 3);
  padDvalueString(strDAT,_KWhr, 100, 8);

  padIvalueString(strDAT, tariff, 1);
  padIvalueString(strDAT, relay, 1);
  padIvalueString(strDAT, sumMeter, 3);
  Serial.println(strDAT);
}

void loop() 
{

}

void padDvalueString(char* _strDAT, double _d, uint8_t _mul, uint8_t _length)
{
  char tmpStr[9];
  for(uint8_t i=0; i<9; i++)
     tmpStr[i] = 'm';  
  uint32_t tmpI;
  tmpI = (uint32_t)(_d*_mul);
  ultoa(tmpI,tmpStr,10);
  Serial.println(tmpStr);
  Serial.println(strnlen(tmpStr,10));
  for (uint8_t i=0; i<(_length-strnlen(tmpStr,10)); i++)
  {
    strncat(_strDAT,"0",1);
  }
  strncat(_strDAT,tmpStr,9);
}

void padIvalueString(char* _strDAT, uint16_t _i, uint8_t _length)
{
  char tmpStr[9];
  for(uint8_t i=0; i<9; i++)
     tmpStr[i] = 'm';
  itoa(_i,tmpStr,10);
  Serial.println(tmpStr);
  Serial.println(strnlen(tmpStr,10));
  for (uint8_t i=0; i<(_length-strnlen(tmpStr,10)); i++)
  {
    strncat(_strDAT,"0",1);
  }
  strncat(_strDAT,tmpStr,9);
}
