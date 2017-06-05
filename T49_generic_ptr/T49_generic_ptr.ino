void passMeAnything(void* pArg) //pArg is a generic pointer can point any type variable 
{
  //Serial.println(*(int*)pArg);  //first consider it as a int type variable's pointer then point its data
  Serial.println(*(float*)pArg);
}


void setup() 
{
  Serial.begin(9600);
  //int val = 3;
  float val = 3;
  passMeAnything(&val);
}

void loop() {
  // put your main code here, to run repeatedly:

}
