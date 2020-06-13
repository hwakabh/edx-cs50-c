#include <stdio.h>


int main()
{
    int age;
    printf("What's your age ?? >> ");
    scanf("%d", &age);

    printf("You are at least %d days old.\n", age * 365);

    return 0;
}
