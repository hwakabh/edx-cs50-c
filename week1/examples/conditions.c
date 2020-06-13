// Conditions and relational operators
#include <stdio.h>


int main()
{
    // Prompt user for x & y
    int x, y;
    printf("x: ");
    scanf("%d", &x);
    printf("y: ");
    scanf("%d", &y);

    // Compare x and y
    if (x < y) {
        printf("x is less than y.\n");
    } else if (x > y) {
        printf("x is greater than y.\n");
    } else {
        printf("x is equal to y.\n");
    }

    return 0;
}
