namespace Ayz
{
  struct Date
  {
    unsigned int d: 5; // d has value between 1 and 31, so 5 bits
    unsigned int m: 4; // m has value between 1 and 12, so 4 bits
    unsigned int y;
  };
}

using namespace Ayz;
struct Date today = {31,12,2017};

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  unsigned int tmp = 9;
  Serial.print("size of unsigned int type variable : ");
  Serial.print(sizeof(tmp));
  Serial.println("bytes");
  Serial.print("size of custom Date variable : ");
  Serial.print(sizeof(today));
  Serial.println("bytes");
  Serial.println("without use of bitfield, 6 bytes would have been allocated for the custom Data type");
}

void loop() {
  // put your main code here, to run repeatedly:

}
