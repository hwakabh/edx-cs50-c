#include <stdlib.h>


void f(void)
{
    int *x = malloc(10 * sizeof(int));
    // // example: buffer overflows
    // x[10] = 0;
    x[9] = 0;
    free(x);
}


int main(void)
{
    // check with valgrind for memory-related issues
    f();
    return 0;
}
