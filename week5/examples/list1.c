// Using malloc() for arrays
// Resizing of array size manually

#include <stdio.h>    // printf()
#include <stdlib.h>   // malloc(), free()


int main(void)
{
    // // Manual declare and initialize
    // int list[3];
    
    // Dynamic allocations
    int *list = malloc(sizeof(int) * 3);
    // malloc returns NULL if out of memory
    if (list == NULL) {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // --- Case if using malloc()
    int *tmp = malloc(sizeof(int) * 4);
    if (tmp == NULL) {
        return 1;
    }

    // Copy integer from old array into new array
    for (int i = 0; i < 3; i++) {
        tmp[i] = list[i];
    }

    tmp[3] = 4;
    // Release memory unused
    free(list);
    // Rename name of array
    list = tmp;

    for (int i = 0; i < 4; i++) {
        printf("%i\n", list[i]);
    }

}
