void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
delay(300);
String S_object = "Arduino";
Serial.println(S_object.length());
char s_array[]= "Arduino";
Serial.println(strlen(s_array));
}

void loop() {
  // put your main code here, to run repeatedly:
}
