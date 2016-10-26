char response[11] = "K1O3KO8K9";
void setup() 
{
Serial.begin(9600);
byte ans = findStr(response, 11, "OK", 3);
Serial.println(ans);
}

void loop() 
{

}

byte findStr(char* mainStr, byte mainLen , char* subStr, byte subLen)
{
  byte ans = 0;
  byte count = 0;
  for(byte i=0; i<mainLen; i++)
     {
      if(mainStr[i]== subStr[count])
        count++;
      else
        count = 0;
      if(count == (subLen-1))
        {
          ans = 1;
          break;
        }
     }
  return ans;
}

