#ifndef _MOVIE_H      //tells compiler to compile this class only once 
#define _MOVIE_H

#include <Arduino.h>

class Movie
{
   public:
          Movie(char* ptrMovieName);
          ~Movie(void);
   private:
          char movieName[50];
};

#endif
