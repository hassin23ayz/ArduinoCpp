// https://www.youtube.com/watch?v=VOpjAHCee7c&list=PL9IEJIKnBJjFiudyP6wSXmykrn67Ykqib

/* 
a linked list is a data structure where elements are chained together by pointer
we will first create a couple of elements and then link them up in a linked list 

we will create a function to print all the elements of a linkedList 
afterwards we will take user input and insert elements to the linkedList 

we will then insert a element at the middle 
we will delete an element at somewhere middle 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NodeS
{
    int data;
    struct NodeS* next;
}NodeT;


void traverse_print(NodeT* pNode)
{
    //we get a pointer and now we will traverse through it until Null is got 

    NodeT* pTrack = pNode;

    while(pTrack->next != NULL)
    {
        printf("%d - ",pTrack->data);
        pTrack = pTrack->next; 
    }
    printf("%d", pTrack->data);
    
    printf("\n\r");
}

NodeT* create_an_element(int value)
{
    NodeT* pNewElem = malloc(sizeof(NodeT));
    pNewElem->data = value;
    pNewElem->next = NULL;
    return pNewElem;
}

void insert_an_element(NodeT* head, int pos, NodeT* pElem)
{
    NodeT* pTrack = head;

    for(int i=1; i<pos; i++)
    {
        pTrack = pTrack->next;
    }

    if(pTrack != NULL)
    {
        NodeT* pKeep = pTrack->next;
        pTrack->next = pElem;
        pElem->next  = pKeep;
    }
}

void delete_an_item(NodeT* head, int index)
{
    NodeT* pTrack = head;
    NodeT* pTrackBefore;
    //go to the indexed elem 
    for(int i=1; i<index; i++)
    {
        pTrackBefore = pTrack;
        pTrack       = pTrack->next;
    }
    //target has arrived
    NodeT* pTarget =  pTrack->next;

    pTrackBefore->next->next = pTarget->next;

    free(pTarget);
}


void main(void)
{
    // creating elements 
    NodeT* pN1 = create_an_element(11);
    NodeT* pN2 = create_an_element(22);
    NodeT* pN3 = create_an_element(33);

    //chaining the elements together
    pN1->next = pN2;
    pN2->next = pN3;

    //let's check the whole linkedList 
    traverse_print(pN1);

    // uptill this point we have 3 elements in the LinkedList and we can create 2 pointer variables to point to them    
    NodeT* head = pN1;
    NodeT* tail = pN3;

    //now we will take user input on how many elements an user wants to add
    int noOfElems2Add = 0 ; 
    printf("Input how many elems you want to add : ");
    scanf("%d", &noOfElems2Add);
    printf("\n\r");

    for (int i = 0; i < noOfElems2Add; i++)
    {
        int userVal = 0;
        printf("insert value for %dth element : ", (i+1) );
        scanf("%d", &userVal);
        printf("\n\r");

        NodeT* pNewNodeNow = create_an_element(userVal);
        tail->next = pNewNodeNow;
        tail = pNewNodeNow;
    }

    //let's check the whole linkedList 
    traverse_print(head);

    //now we will insert an element in the middle of the LinkedList
    printf("Input at which index you want to add an element : ");
    int insertIndex; 
    scanf("%d", &insertIndex);
    printf("\n\r");

    int userVal2;
    printf("insert value for %dth element : ", insertIndex );
    scanf("%d", &userVal2);
    printf("\n\r");

    NodeT* pN_indexed = create_an_element(userVal2);
    insert_an_element(head, insertIndex, pN_indexed);

    //let's check the whole linkedList 
    traverse_print(head);

    //now we will delete an element in the middle of the LinkedList
    printf("Input at which index you want to delete an element : ");
    int delIndex; 
    scanf("%d", &delIndex);
    printf("\n\r");

    delete_an_item(head, delIndex);
    //let's check the whole linkedList 
    traverse_print(head);    
}