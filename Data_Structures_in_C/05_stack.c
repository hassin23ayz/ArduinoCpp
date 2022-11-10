// https://www.youtube.com/watch?v=A4sRhuGkRb0&list=PL9IEJIKnBJjFiudyP6wSXmykrn67Ykqib&index=6

// stack is a simple Linear Data Structure 

// STACK is FILO : first in last out , like a pile of books 
// QUEUE is FIFO : first in first out 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

#define STACK_SZ    5
#define STACK_EMPTY -2147483648

int data[STACK_SZ];  // this is a simple array
int top = -1;        // Stack has only one variable to refer elements
                     // starting from -1 really helps a lot 

void push(int v)
{
    if(top >= STACK_SZ)
    {
        printf("Stack is full\n\r");
        return;
    }
    else
    {
        top++;
        data[top] = v;
    }
}

int pop(void)
{
    if(top <= -1)
    {
        printf("Stack is empty\n\r");
        return STACK_EMPTY;
    }
    else
    {
        return data[top--];
    }
}


void main(void)
{
    // read empty stack
    int readData = pop();

    push(11);
    push(22);
    push(33);
    push(44);
    push(55);
    push(66);
    push(77);
    push(88);

    printf("--------------------\n\r");
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n\r", pop());
    }

}

