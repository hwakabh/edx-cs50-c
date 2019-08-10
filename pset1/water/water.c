#include <stdio.h>

int main(void)
{
    int minutes;
    // TODO: Bugfix when user entered string(s)
    do
    {
        printf("Minutes : ");
        scanf("%d", &minutes);
    }
    while (minutes <= 0);

    printf("Bottle : %d\n", minutes * 12);

    return 0;
}