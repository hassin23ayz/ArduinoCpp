// https://www.youtube.com/watch?v=2Ti5yvumFTU&list=PL9IEJIKnBJjFiudyP6wSXmykrn67Ykqib&index=3


// A Hash function takes an input and map that input into a location in an array 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SZ 16
#define MAX_NAME 64

typedef struct {
    char name[MAX_NAME];
    int  age;
}PersonT;

PersonT persons_table[TABLE_SZ];



void print_person_table(void)
{

    for (int i = 0; i < TABLE_SZ; ++i)
    {
        /* code */
        printf("[%s](%d)\n\r", persons_table[i].name, persons_table[i].age);
    }

}

void insert_elem_to_table(PersonT p)
{
    // todo calculate hash index and put 
    persons_table[0] = p;



}

void main(void)
{
    PersonT p1 = {.name = "ayman", .age = 1};
    insert_elem_to_table(p1);

    print_person_table();

}



