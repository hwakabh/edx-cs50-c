import re
from cs50 import get_string

s = get_string("Do you agree?\n")

# basic OR conditions
if s == "Y" or s == "y":
    print("Agreed.")
elif s == "N" or s == "n":
    print("Not agreed.")


# More user-friendly ways with accepting case-insensitive
if s.lower() in ["y", "yes"]:
    print("Agreed.")
elif s in ["n", "no", "nope", ]
    print("Not agreed.")


# If using regexp
if re.search("^y(es)?$", s, re.IGNORECASE):
    print("Agreed.")
elif re.search("^n(o)?$", s):
    print("Not agreed.")
