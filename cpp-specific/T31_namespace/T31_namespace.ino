namespace First
{
  int x = 5;
}

namespace Second
{
  int x = 10;
  int y = 7;
}

void setup() 
{
  Serial.begin(9600);
  using namespace First;
  Serial.println(x);
  using namespace Second;
  Serial.println(y);
  func();  
}
using namespace Second;
void func()
{
  //using namespace Second;
  Serial.println(x);  
}

void loop()
{}
