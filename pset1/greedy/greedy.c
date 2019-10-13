#include <stdio.h>
#include <math.h>

const int QUARTER = 25;
const int DIME = 10;
const int NICKEL = 5;
const int PENNY = 1;

int main(void)
{
    float dollar_owed;
    int cents_owed;
    int coins = 0;

    // TODO: Escape closed loop when user entered string(s)
    do {
        printf("Please enter amounts of change[$]: ");
        if (scanf("%f", &dollar_owed) != 1) {
            printf("Please enter numeric numbers, string format is not supported.\n");
            return 1;
        }
        cents_owed = round(dollar_owed * 100);
    } while (cents_owed <= 0);

    while ((cents_owed / QUARTER) != 0) {
        coins++;
        cents_owed -= QUARTER;
    }

    while ((cents_owed / DIME) != 0) {
        coins++;
        cents_owed -= DIME;
    }

    while ((cents_owed / NICKEL) != 0) {
        coins++;
        cents_owed -= NICKEL;
    }

    while ((cents_owed / PENNY) != 0) {
        coins++;
        cents_owed -= PENNY;
    }

    printf("Coins : %d\n", coins);
    return 0;
}

