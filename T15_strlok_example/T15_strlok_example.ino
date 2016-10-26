char string[] = "ABCD\"1234\"EFGH";
char str2[] = "0010POL10082015102100MD01";

void setup() 
{
  Serial.begin(9600);
  char* parsedStr;
  parsedStr = strtok(string,"\"");
  Serial.println(parsedStr);
  parsedStr = strtok(NULL,"\"");
  Serial.println(parsedStr);

  char ts[15];
  char* pch;
  pch = strtok(str2,"LM");
  byte i=1;
  while (pch != NULL)
  {
    //printf ("%s\n",pch);
    Serial.println(pch);
    pch = strtok (NULL, "LM");
    i++;
    if(i==2)
      {
        Serial.print("*");
        strcpy(ts,pch);
      }
  }
  Serial.print("Time Stamp is :");
  Serial.println(ts);
}

void loop() 
{
}
