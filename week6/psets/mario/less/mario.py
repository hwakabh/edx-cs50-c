from cs50 import get_int


def main():
    while True:
        # Get user-input
        h = get_int("Height: ")
        if 1 <= h and h <= 8:
            break

    # Print out blocks
    for i in range(1, h + 1):
        print(" " * (h - i) + "#" * i)


main()
