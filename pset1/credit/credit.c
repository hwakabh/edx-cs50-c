#include <stdio.h>
#include <math.h>

int get_digits_number(long n);

int main(void)
{
    long cc_number;
    printf(">>> Please enter your card number : ");
    scanf("%ld", &cc_number);

    // Validation with digit numbers
    int nd = get_digits_number(cc_number);

    int cc_numbers[nd];
    for (int i = nd; i > 0 ; i--) {
        int num = cc_number / pow(10, i - 1);
        cc_numbers[nd - i] = num;
        cc_number = cc_number - (num * pow(10, i - 1));
    }

    // Checksum calculation
    int subtotal = 0;
    int reminders = 0;
    int num_flag = nd % 2;
    for (int m = num_flag; m < nd ; m += 2) {
        if ((cc_numbers[m] * 2) > 9) {
            subtotal += ((cc_numbers[m] * 2) / 10) + ((cc_numbers[m] * 2) % 10);
        } else {
            subtotal += (cc_numbers[m] * 2);
        }
    }
    for (int n = 1 - num_flag; n < nd ; n += 2) {
        reminders += cc_numbers[n];
    }

    // MOD-10 Check
    if ((subtotal + reminders) % 10 != 0) {
        printf(">>> Invalid Card with checksum.\n");
    } else {
        if (nd == 15) {
            // Validation with first numbers for AMEX
            if (cc_numbers[0] == 3) {
                if (cc_numbers[1] == 4 || cc_numbers[1] == 7) {
                    printf(">>> AMEX Card number entered.\n");
                } else {
                    printf(">>> INVALID : Please check second number of input.\n");
                }
            } else {
                printf(">>> INVALID : Please check first number of input.\n");
            }

        } else if (nd == 13) {
            // Validation with first numbers for VISA
            if (cc_numbers[0] == 4) {
                printf(">>> VISA Card number entered.\n");
            } else {
                printf(">>> INVALID : Please check first number of input.\n");
            }

        } else if (nd == 16) {
            // Validation with First number
            if (cc_numbers[0] == 4) {
                printf(">>> VISA Card number entered.\n");
            } else if (cc_numbers[0] == 5) {
                if (cc_numbers[1] == 1 || cc_numbers[1] == 2 || cc_numbers[1] == 3 || cc_numbers[1] == 4 || cc_numbers[1] == 5 ) {
                    printf(">>> MASTER Card number entered.\n");
                } else {
                    printf(">>> INVALID : Please check second number of input.\n");
                }
            } else {
                printf(">>> INVALID : Please check first number of input.\n");
            }

        } else {
            printf(">>> INVALID : Please check digits.\n");
            return 1;
        }
    }
}


int get_digits_number(long n)
{
    int digit = 0;
    while (n != 0) {
        n /= 10;
        digit++;
    }
    return digit;
}
