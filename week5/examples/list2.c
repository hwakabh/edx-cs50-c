// Use of realloc() instead of malloc()

#include <stdio.h>    // printf()
#include <stdlib.h>   // realloc(), free()


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

    // --- Case if using realloc() instead of malloc()
    int *tmp = realloc(list, sizeof(int) * 4);
    if (tmp == NULL) {
        return 1;
    }

    // Rename name of array
    list = tmp;
    tmp[3] = 4;
    // Release memory unused
    free(list);

    for (int i = 0; i < 4; i++) {
        printf("%i\n", list[i]);
    }

}
