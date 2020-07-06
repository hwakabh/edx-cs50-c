#include <stdio.h>    // printf()
#include <stdlib.h>   // malloc()


int main(void)
{
    int *x;
    int *y;

    // Reserve the memories for x
    x = malloc(sizeof(int));

    *x = 42;
    // It's bug since the memory for y have not reserved yet
    // *y = 13;

    // Copy address of pointed by pointer
    // Note that this is not copying 42 to y
    x = y;

    // Value 42 is overwritten, since pointer y is pointed same address as pointer x
    *y = 13;
}
