from sys import argv, exit
from cs50 import SQL


def main():
    # Check command line arguments
    if len(argv) != 2:
        print("Missing command line arguments.")
        print(f"Usage: python {argv[0]} housename")
        exit(1)

    # Connect to database
    db = SQL("sqlite:///students.db")
    # Get records from SQLite3
    students = db.execute(
        "SELECT * FROM students WHERE house = ? ORDER BY last, first",
        argv[1]
    )

    for student in students:
        record = f"{student['first']} "
        if student.get("middle", None) is not None:
            record += f"{student['middle']} "
        record += f"{student['last']}, born {student['birth']}"

        print(record)


main()