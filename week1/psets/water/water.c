#include <stdio.h>
#include <ctype.h>

const int ounce_per_min = 192;
const int ounce_per_bottle = 16;

int main(void)
{
    int minutes;
    do {
        printf("Minutes : ");
        if (scanf("%d", &minutes) != 1) {
            printf("Please enter numeric values, string format is not supported.\n");
            return 1;
        }
    } while (minutes <= 0);

    int bottle_per_min = (ounce_per_min / ounce_per_bottle) * minutes;
    printf("Bottles : %d\n", bottle_per_min);

    return 0;
}
