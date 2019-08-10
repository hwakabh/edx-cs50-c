#include <stdio.h>

int get_digits_number(int number);

int main(void)
{
    int user_input;
    printf("Please enter your card number : ");
    scanf("%d", &user_input);
    
    int n = get_digits_number(user_input);

    int card_number[n];
    printf("Digits of input : %d\n", n);
    printf("Card Number : %d\n", user_input);
    return 0;
}


int get_digits_number(int number)
{
    int digit = 0;
    while (number != 0)
    {
        number = number / 10;
        digit++;
    }
    return digit;
}