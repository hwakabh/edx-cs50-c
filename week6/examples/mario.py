for i in range(4):
    # print() has default parameter for `end` with "\n"
    print("?", end="")
print()

# More Pythonic way
print("?" * 4, end="")
print()


# Printing Mario's blocks with 1-demension
print("#\n" * 3, end="")

# Printing Mario's blocks with 2-demensions
for i in range(3):
    for j in range(3):
        print("#", end="")
    print()