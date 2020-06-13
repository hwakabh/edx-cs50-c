#include <stdio.h>


int main()
{
    // Prompt user for integer
    float x, y;
    printf("x: ");
    scanf("%f", &x);
    printf("y: ");
    scanf("%f", &y);

    printf("x / y = %f\n", x / y);
    printf("x / y = %.1f\n", x / y);
    // Computer stores the closest possible match for the result
    // You can not possibly store an infinite number of number, 100% precisely using a finite amount of information
    printf("x / y = %.10f\n", x / y);
    printf("x / y = %.50f\n", x / y);

    return 0;
}
