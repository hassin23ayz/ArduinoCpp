void setup() 
{
  Serial.begin(9600);
  Serial.println(__TIME__);
  Serial.println(__DATE__);
  
  //sscanf(): reads formatted input from string
  int _hour, _min, _sec;
  sscanf(__TIME__, "%d:%d:%d", &_hour, &_min, &_sec);
  Serial.print("parsed Time: ");
  Serial.print(_hour);
  Serial.write(':');
  Serial.print(_min);
  Serial.write(':');
  Serial.println(_sec);  
}

void loop() 
{
}
