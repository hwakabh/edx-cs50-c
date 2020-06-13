#include <stdio.h>


int main()
{
    float price;
    printf("What's the price ?? >>> ");
    scanf("%f", &price);

    printf("Your total is %.2f.\n", price * 1.0625);

    return 0;
}
