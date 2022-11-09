// in single linked list we can only travel forward 
// what if we need to go backwards as well , ths answer is doubly Link List 
// https://www.youtube.com/watch?v=e9NG_a6Z0mg&list=PLBlnK6fEyqRj9lld8sWIUNwlKfdUoPd1Y&index=65

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct NodeS{
    struct NodeS* prev;
    int data;
    struct NodeS* next;
}NodeT;


NodeT* create_an_element(int value)
{
    NodeT* pNewElem = malloc(sizeof(NodeT));
    pNewElem->data = value;
    pNewElem->next = NULL;
    pNewElem->prev = NULL;
    return pNewElem;
}

void traverse_print_backwards(NodeT* pNode)
{
    //we get a pointer and now we will traverse through it until Null is got 

    NodeT* pTrack = pNode;

    while(pTrack->prev != NULL)
    {
        printf("%d - ",pTrack->data);
        pTrack = pTrack->prev; 
    }
    printf("%d", pTrack->data);
    
    printf("\n\r");
}

void main(void)
{

    // creating elements 
    NodeT* pN1 = create_an_element(11);
    NodeT* pN2 = create_an_element(22);
    NodeT* pN3 = create_an_element(33);

    //chaining the elements together
    pN1->prev = NULL;
    pN1->next = pN2;

    pN2->prev = pN1;
    pN2->next = pN3;

    pN3->prev = pN2;
    pN3->next = NULL;

    //let's check the whole linkedList but as backwards 
    traverse_print_backwards(pN3);


}

