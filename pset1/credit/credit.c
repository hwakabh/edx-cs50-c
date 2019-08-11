#include <stdio.h>
#include <math.h>

// Checksums
// - AMEX :
//   - 15 digits
//   - starts with 34 or 37
// - MasterCard :
//   - 16 digits
//   - starts with 51, 52, 53, 54, 55
// - Visa :
//   - 13 or 16 digits
//   - starts with 4
// Examples:
// - AMEX : 378282246310005 / 371449635398431 / 378734493671000
// - MASTER : 2221000000000009 / 2223000048400011 / 2223016768739313 / 5555555555554444 / 5105105105105100
// - VISA : 4111111111111111 / 4012888888881881 / 4222222222222

int get_digits_number(long n);
// int check_card_number(long n, int d);

int main(void)
{
    long cc_number;
    printf(">>> Please enter your card number : ");
    scanf("%ld", &cc_number);

    // Validation with digit numbers
    int nd = get_digits_number(cc_number);
    printf("%d digit(s) number was entered.\n", nd);

    int cc_numbers[nd];
    for (int i = nd; i > 0 ; i--) {
        int num = cc_number / pow(10, i - 1);
        cc_numbers[nd - i] = num;
        cc_number = cc_number - (num * pow(10, i - 1));
    }


    // printf("Each of numbers in array : \n");
    // for (int j = 0; j < nd; j++) {
    //     printf("%d\n", cc_numbers[j]);
    // }


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


int get_digits_number(long n)
{
    int digit = 0;
    while (n != 0) {
        n /= 10;
        digit++;
    }
    return digit;
}

/**
 * Checksum Example:
 *
 * 378282246310005
 *  - - - - - - -
 *
 * 0*2 + 0*2 + 3*2 + 4*2 + 2*2 + 2*2 + 7*2 = 27
 *
 * 378282246310005
 * - - - - - - - -
 *
 * 3 + 8 + 8 + 2 + 6 + 1 + 0 + 5 = 33
 *
 * 27 + 33 = 60
 *
 * 60 % 10 == 0 / VALID CARD
 *
 */