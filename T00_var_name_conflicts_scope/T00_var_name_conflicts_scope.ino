String var = "Global";
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
String var = "Local";
Serial.println(var);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(var);
delay(1000);
}
