from cs50 import get_string

s = get_string("What's your name?\n")

print("hello,", s)
# Same as:
print("hello, " + s)
print(f"hello, {s}")