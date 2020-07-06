from sys import exit
from math import log10
from cs50 import get_int


def main():
    while True:
        # Using get_int instead of get_string for re-prompting
        # when user provide some string values
        card_number = get_int("Number: ")

        # Check number of digits(note log10 returns type:float)
        num_digit = int(log10(card_number) + 1)
        if num_digit == 13 or num_digit == 15 or num_digit == 16:
            break
        else:
            print("INVALID")
            exit(1)

    # Calculate checksum of card
    num_second_to_last = [
        str(card_number)[::-1][i]
        for i in range(1, len(str(card_number)), 2)
    ]

    products = 0
    for d in num_second_to_last:
        if int(d) * 2 > 9:
            products += (int(d) * 2 ) // 10 + (int(d) * 2) % 10
        else:
            products += int(d) * 2

    # Check modulo-10
    num_rest = [
        int(str(card_number)[::-1][i])
        for i in range(0, len(str(card_number)), 2)
    ]
    products += sum(num_rest)
    if products % 10 != 0:
        print("INVALID")
        exit(1)

    # Card brand check
    if num_digit == 15:
        if str(card_number)[:2] == "34" or str(card_number)[:2] == "37":
            print("AMEX")
            exit(0)
    elif num_digit == 13:
        if str(card_number)[:1] == "4":
            print("VISA")
            exit(0)
    elif num_digit == 16:
        if str(card_number)[:1] == "4":
            print("VISA")
            exit(0)
        if str(card_number)[:1] == "5":
            print("MASTERCARD")
            exit(0)
    else:
        print("INVALID")
        exit(1)


main()