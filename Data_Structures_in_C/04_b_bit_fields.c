// set , clear , toggle and check a bit 
// https://www.youtube.com/watch?v=aMAM5vL7wTs&list=PL9IEJIKnBJjFiudyP6wSXmykrn67Ykqib&index=4 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

#define SET_BIT(BF, N)     BF |=  ((uint8_t)1 << N)
#define CLR_BIT(BF, N)     BF &= ~((uint8_t)1 << N) 
#define TOG_BIT(BF, N)     BF ^=  ((uint8_t)1 << N) 

// #define IS_BIT_SET(BF, N)  ((BF >> N) & 0x1) 
#define IS_BIT_SET(BF, N)  (((uint8_t)1 << N) & BF) 

void print_val(uint8_t v)
{
    for (int i = 7; i >= 0 ; i--)
    {
        if(IS_BIT_SET(v, i))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\n\r");
}

 
void main(void)
{

    uint8_t val = 23; 
    print_val(val);

    val = SET_BIT(val, 3);
    print_val(val);

    val = CLR_BIT(val, 4);
    print_val(val);

    val = TOG_BIT(val, 0);
    print_val(val);

}