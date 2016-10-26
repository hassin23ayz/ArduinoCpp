enum day
     {
      Mon,
      Tue,
      Wed,
      Thu,
      Fri,
      Sat,
      Sun
     };

enum day holiday;

day listen_office_holiday();

void setup() 
{
  //holiday = Sun;
  Serial.begin(9600);
  holiday = listen_office_holiday();
  Serial.println("hey man!!! My office decided to give holiday at ");
  Serial.print(holiday);
}

void loop() 
{
}

day listen_office_holiday()
{
  return Sun;
}




