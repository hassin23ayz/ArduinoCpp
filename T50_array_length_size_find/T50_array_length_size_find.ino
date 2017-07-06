void setup() 
{
  Serial.begin(9600);
  Serial.println(" length(), sizeOf() operator test");

  uint8_t definedArray[] = {1,6,3,9,2,3,1,0};
  char definedArray2[] = "abcdefgh";
  uint16_t declaredArray[16];

  Serial.print("definedArray size:");
  Serial.println(sizeof(definedArray)/sizeof(uint8_t));

  Serial.print("definedArray2 size:");
  Serial.println(sizeof(definedArray2)/sizeof(char));

  Serial.print("declaredArray size:");
  Serial.println(sizeof(declaredArray)/sizeof(uint16_t));

  String str = "hjfkjfk";
  Serial.print("str size:");
  Serial.println(str.length());

  //length wont work on first 3 arrays here , works only on String type object 
  //sizeof() returns the number of bytes taken
}

void loop() {
  // put your main code here, to run repeatedly:

}
