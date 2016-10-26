int* getIntArray();

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 int m[10] = {9,8,7,6,5,4,3,2,1,0};
 int* ptr_n;
 ptr_n = getIntArray(m);
 for(byte i=0; i<10; i++)
 {
  Serial.println(*(ptr_n+i)); 
 }
}

void loop() {
  // put your main code here, to run repeatedly:

}

int* getIntArray(int* ptr_m)
{
  static int n[10] = {0,1,2,3,4,5,6,7,8,9};
  for(byte i=0; i<10; i++)
  {
    n[i] = *(ptr_m+i);
  }
  return n;  
}


