void setup() 
{
  Serial.begin(9600);

  Serial.print("char:");
  char ch = 65; //65 means A
  Serial.write(ch);
  Serial.write('\n');
  Serial.println(ch,DEC);
  Serial.println(ch,BIN);
  
  Serial.print("unsigned char:"); 
  unsigned char uch = 65;
  Serial.write(uch);
  Serial.write('\n');
  Serial.println(uch,DEC);
  Serial.println(uch,BIN);
  
  Serial.print("char:");         
  char ch2 = 143; //143 means Ao  //this will create bugs
  Serial.write(ch2);
  Serial.write('\n');
  Serial.println(ch2,DEC);
  Serial.println(ch2,BIN);
  
  Serial.print("unsigned char:"); 
  unsigned char uch2 = 143;
  Serial.write(uch2);
  Serial.write('\n');
  Serial.println(uch2,DEC);
  Serial.println(uch2,BIN);  
}

void loop() 
{
}
