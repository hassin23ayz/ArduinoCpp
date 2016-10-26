
void setup() {
  // put your setup code here, to run once:
Serial.begin(57600);
byte b = 0x61;
Serial.println((char)b);
Serial.println(b,HEX);

char ch = 'a';
Serial.println(ch);
Serial.println(ch,HEX);

char array[] = "ABCD";
Serial.println(array);
Serial.println(strlen(array));
for(int i=0; i<strlen(array); i++)
   {
    Serial.println(array[i]);
   }
String str = "EFGH";
Serial.println(str);
Serial.println(str.length());
for(int i=0; i<str.length(); i++)
   {
    Serial.println(str[i]);
   }   
}


void loop() {
  // put your main code here, to run repeatedly:

}
