#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char greeting[] = "hello";

    printf("sizeof(greeting) = %d \n\r", sizeof(greeting)); //6 bytes
    printf("strlen(greeting) = %d \n\r", strlen(greeting)); //5 bytes
    return 0;
}
