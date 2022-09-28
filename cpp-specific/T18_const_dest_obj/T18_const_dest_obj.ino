#include "Movie.h"

void setup() 
{
  Serial.begin(9600);
  Movie dvd_0("Ride the Divide");
  delay(3000);
}

void loop() 
{
  watchNextMovie();
  delay(3000); 
  exit(0);  
}

void watchNextMovie(void)
{
  Movie dvd_1("The Armstrong lie"); 
}
