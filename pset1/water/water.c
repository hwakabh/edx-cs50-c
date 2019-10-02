#include <stdio.h>
#include <ctype.h>

const int ounce_per_min = 192;
const int ounce_per_bottle = 16;

int main(void)
{
    int minutes;
    // TODO: Bugfix when user entered string(s)
    do {
        printf("Minutes : ");
        scanf("%d", &minutes);
    } while (minutes <= 0);

    int bottle_per_min = (ounce_per_min / ounce_per_bottle) * minutes;
    printf("Bottles : %d\n", bottle_per_min);

    return 0;
}
