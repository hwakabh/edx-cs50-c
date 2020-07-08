from csv import DictReader
from sys import argv, exit
from cs50 import SQL


def main():
    # Check command line arguments
    if len(argv) != 2:
        print("Missing command line arguments.")
        print(f"Usage: python {argv[0]} characters.csv")
        exit(1)
    if argv[1][-4:] != ".csv":
        print("Provided argument(s) is wrong.")
        exit(1)

    # Close file if done not database file already opened
    open("students.db", "w").close()
    # Connect to database
    db = SQL("sqlite:///students.db")
    # Create table to store data
    db.execute("CREATE TABLE students (first VARCHAR(255), middle VARCHAR(255), last VARCHAR(255), house VARCHAR(10), birth INTEGER)")

    # Load CSV files
    with open(argv[1], "r") as file:
        reader = DictReader(file)

        for row in reader:
            names = row["name"].split()
            house = row["house"]
            birth = row["birth"]

            # Parse each student name
            first = names[0]
            if len(names) == 3:
                middle = names[1]
                last = names[2]
            elif len(names) == 2:
                middle = None
                last = names[1]

            db.execute(
                "INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",
                first, middle, last, house, birth
            )


main()