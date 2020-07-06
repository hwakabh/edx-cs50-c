from cs50 import get_string

s = get_string("Input: ")
print("Output: ", end="")

# C's way
for i in range(len(s)):
    print(s[i], end="")
print()

# Pythonic way
for c in s:
    print(c, end="")
print()
