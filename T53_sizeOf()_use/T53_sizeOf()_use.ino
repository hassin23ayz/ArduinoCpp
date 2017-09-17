void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  char meterNo[]="541610054310";

  Serial.println(sizeof(meterNo));
  Serial.println(sizeof(meterNo[0]));
  
  Serial.print("number of elements in the char type meterNo[] array:");
  Serial.println(sizeof(meterNo)/sizeof(meterNo[0]));


  int food[] = {5,6,7,8,9,2};
  Serial.println(sizeof(food));
  Serial.println(sizeof(food[0]));
  
  Serial.print("number of elements in the int type food[] array:");
  Serial.println(sizeof(food)/sizeof(food[0]));
}

void loop() {
  // put your main code here, to run repeatedly:

}
