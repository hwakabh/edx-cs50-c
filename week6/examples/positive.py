from cs50 import get_int


def main():
    i = get_positive_int()
    print(i)


def get_positive_int():
    while True:
        n = get_int("Positive Integer: ")
        if n > 0:
            break
    # Python's variable is accessible outside the block
    # but inaccessible across functions
    return n
