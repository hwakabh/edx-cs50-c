from csv import DictReader
from cs50 import SQL

# Create empty shows3.db
open("./srcdata/shows4.db", "w").close()

# Open that file for SQLite
db = SQL("sqlite:///shows4.db")

# Create tables called shows in database file called shows3.db
db.execute("CREATE TABLE shows (id INT, title TEXT, year NUMERIC, PRIMARY_KEY(id))")
db.execute("CREATE TABLE genres (show_id INT, genre TEXT, FOREIGN_KEY(show_id) REFERENCES shows(id))")

# Open source data
with open("title.basics.tsv") as titles:
    # Create DictReader
    reader = DictReader(titles, delimiter="\t")

    for row in reader:
        if row["titleType"] == "tvSeries" and row["isAdult"] == "0":
            if row["startYear"] != "\\N":
                startYear = int(row["startYear"])

                if startYear >= 1970:
                    tconst = row["tconst"]
                    primaryTitle = row["primaryTitle"]
                    genres = row["genres"]

                    # Insert data into tables
                    # note that ? is placeholder for sqlite
                    db.execute("INSERT INTO shows (tconst, primaryTitle, startYear, genres) VALUES(?, ?, ?, ?)",
                        tconst, primaryTitle, startYear, genres
                    )
