// Abstructions and scope
#include <stdio.h>

int get_positive_int(void);


int main()
{
    int i = get_positive_int();
    printf("%d\n", i);

    return 0;
}


// Prompt user for positive integer
int get_positive_int(void)
{
    int n;
    do {
        printf("Positive integer: ");
        scanf("%d", &n);
    } while (n < 1);

    return n;
}
