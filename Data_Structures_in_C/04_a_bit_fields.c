// https://youtu.be/aMAM5vL7wTs?list=PL9IEJIKnBJjFiudyP6wSXmykrn67Ykqib 

// pack data to the fewest number of bits 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

struct Mytype{
    uint16_t m:9;
    uint16_t n:9;
    uint16_t t:9;
};

typedef struct Mytype Mytype;

//----------------------------
struct Mytype2{
    uint16_t m:9;
    uint16_t n:9;
    uint16_t t:9;
}__attribute__((packed));

typedef struct Mytype2 Mytype2;

void main(void)
{
    printf("%d \n\r", sizeof(Mytype));

    printf("%d \n\r", sizeof(Mytype2));
}