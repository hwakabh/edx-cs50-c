#include <stdio.h>


int main(void)
{
    int x;
    printf("x: ");
    scanf("%i", &x);
    printf("x: %i\n", x);

    // // initialize with null-pointer
    // char *s = NULL;
    char s[5];
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);

    return 0;
}
