from cs50 import get_float

# consts
QUARTER = 25
DIME = 10
NICKEL = 5
PENNY = 1


def main():
    count = 0
    doller_owed = 0

    while True:
        doller_owed = get_float("Change owed: ")
        cents_owed = round(doller_owed * 100)
        if not cents_owed <= 0:
            break

    ## Greedy algorithms
    while (cents_owed // QUARTER) != 0:
        count += 1
        cents_owed -= QUARTER

    while cents_owed // DIME != 0:
        count += 1
        cents_owed -= DIME

    while cents_owed // NICKEL != 0:
        count += 1
        cents_owed -= NICKEL

    while cents_owed // PENNY != 0:
        count += 1
        cents_owed -= PENNY

    print(count)


main()