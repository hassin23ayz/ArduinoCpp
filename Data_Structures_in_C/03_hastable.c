// https://www.youtube.com/watch?v=2Ti5yvumFTU&list=PL9IEJIKnBJjFiudyP6wSXmykrn67Ykqib&index=3


// A Hash function takes an input and map that input into a location in an array 

//TODO: collision handling 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

#define TABLE_SZ 16
#define MAX_NAME 64

typedef struct {
    char name[MAX_NAME];
    int  age;
}PersonT;

// a hash table is a pointer array to point to data elems
PersonT* hash_table[TABLE_SZ];

// hash function computes an sum and multiple combo  
uint32_t hash_get(char* name)
{
    uint32_t hash = 0;
    for (int i = 0; i < strlen(name); i++)
    {
        hash += name[i] ;
        hash  = (hash * name[i]) % TABLE_SZ;     
    }
    return hash;
}
// goes through the pointer type hash array table and prints each elem values 
void hash_table_print(void)
{
    printf("----------------------------------\n\r");
    for (int i = 0; i < TABLE_SZ; i++)
    {
        if(hash_table[i] == NULL){
            // the slot in this index was not filled 
            printf("[-](-)\n\r");    
        }
        else{
            PersonT* pPerson = hash_table[i];
            printf("[%s](%d)\n\r", pPerson->name, pPerson->age);
        }
    }
}
// hash_table pointer slots are initialized as NULL 
void init_hash_table(void)
{
    for (int i = 0; i < TABLE_SZ; i++)
    {
        hash_table[i] = NULL;
    }
}
// gets hash and computes an index within boundary , puts the arg elem to the indexed slot  
bool hash_table_insert(PersonT* p)
{
    int index = hash_get(p->name) % TABLE_SZ; // % modulo operator wraps the index within TABLE_SZ 
    
    if (hash_table[index] != NULL)
    {
        // already used
        return false;
    }
    else
    {
        hash_table[index] = p;
        return true;
    }
}

// read element from the hash table by lookup
PersonT* hash_table_lookup(char* name)
{
    // use the same hash compute function to get the index at which data is 
    int indexLookUp = hash_get(name);

    if(hash_table[indexLookUp] == NULL){
        // nothing found in this index so returning NULL
        return NULL;
    }
    else
    {
        if( strncmp(hash_table[indexLookUp]->name, name, strlen(name)) == 0 )
        {
            return hash_table[indexLookUp];
        }
        else
        {
            return NULL;
        }
    }
    return NULL;
}

void hash_table_delete(char* name)
{
    // use the same hash compute function to get the index at which data is 
    int indexLookUp = hash_get(name);

    if(hash_table[indexLookUp] != NULL)
    {
        if( strncmp(hash_table[indexLookUp]->name, name, strlen(name)) == 0 )
        {
            hash_table[indexLookUp] = NULL;
        }
    }
}

//---------------------------------------------------------------------------------------------------
void main(void)
{
    PersonT p1 = {.name = "ayman", .age = 1};
    PersonT p2 = {.name = "tom", .age = 1};
    PersonT p3 = {.name = "jerry", .age = 1};
    hash_table_insert(&p1);
    hash_table_insert(&p2);
    hash_table_insert(&p3);
    hash_table_print();

    // lookup from the table 
    PersonT* p = hash_table_lookup("ayman");

    // delete an item from the table
    hash_table_delete("tom");
    hash_table_print();

}



