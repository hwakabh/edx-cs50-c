#include <stdio.h>

void swap(int *a, int *b);


int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    // throw the address of x, y as args of function
    swap(&x, &y);
    printf("x is %i, y is %i\n", x, y);

    return 0;
}


void swap(int *a, int *b)
{
    // *a means goto(a), so this represents x
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
