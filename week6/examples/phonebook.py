# handling file
import csv

from cs50 import get_string


name = get_string("Name: ")
number = get_string("Number: ")

# If use `with`, the file.close() runs automatically
with open("phonebook.csv", "a") as file:
    writer = csv.writer(file)
    writer.writerow((name, number))

# file = open("phonebook.csv", "a")
# writer = csv.writer(file)
# writer.writerow((name, number))
# file.close()
