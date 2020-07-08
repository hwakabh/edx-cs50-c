from csv import DictReader


title = input("Title: ")

with open("show2.csv", "r") as file:
    reader = DictReader(file)

    for row in reader:
        if title == row["primaryTitle"]:
            print(row["primaryTitle"], row["startYear"])
