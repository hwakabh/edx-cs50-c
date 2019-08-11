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
int check_card_number(long n);

int main(void)
{
    long cc_number;
    printf(">>> Please enter your card number : ");
    scanf("%ld", &cc_number);

    // Validation with digit numbers
    int nd = get_digits_number(cc_number);
    printf("%d digit(s) number was entered.\n", nd);

    int num_first = cc_number / pow(10, nd - 1);
    printf("First digit number is : %d\n", num_first);

    int num_second = (cc_number - (num_first * pow(10, nd - 1))) / pow(10, nd -2);
    printf("Second digit number is : %d\n", num_second);

    if (nd == 15) {
        // Checksum Calculation for AMEX

        // Validation with first numbers for AMEX
        if (num_first == 3) {
            if (num_second == 4 || num_second == 7) {
                printf(">>> AMEX Card number entered.\n");
            } else {
                printf(">>> INVALID : Please check second number of input.\n");
            }
        } else {
            printf(">>> INVALID : Please check first number of input.\n");
        }


    } else if (nd == 13) {
        // Checksum Calculation for VISA

        // Validation with first numbers for VISA
        if (num_first == 4) {
            printf(">>> VISA Card number entered.\n");
        } else {
            printf(">>> INVALID : Please check first number of input.\n");
        }


    } else if (nd == 16) {
        // Checksum Calculation for VISA

        // Validation with First number
        if (num_first == 4) {
            printf(">>> VISA Card number entered.\n");
        } else if (num_first == 5) {
            if (num_second == 1 || num_second == 2 ||  num_second == 3 || num_second == 4 || num_second == 5 ) {
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

// // Functions for get checksum
// int check_card_numer(long n)
// {

// }

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