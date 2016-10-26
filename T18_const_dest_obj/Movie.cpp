#include "Movie.h"

Movie::Movie(char* ptrMovieName)
{
  strcpy(movieName,ptrMovieName);
  Serial.print(movieName);
  Serial.println(" movie has Started ...");
}

Movie::~Movie(void)
{
  Serial.print(movieName);
  Serial.println(" movie has finished"); 
}

