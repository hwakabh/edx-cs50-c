from csv import DictReader
from cs50 import SQL

# Create empty shows3.db
open("./srcdata/shows3.db", "w").close()

# Open that file for SQLite
db = SQL("sqlite:///shows3.db")

# Create tables called shows in database file called shows3.db
db.execute("CREATE TABLE shows (tconst TEXT, primaryTitle TEXT, startYear NUMERIC, genres TEXT)")
print("Create table done")

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
                    print(f"Loading data [ {tconst}, {primaryTitle} ] to tables ...")
                    db.execute("INSERT INTO shows (tconst, primaryTitle, startYear, genres) VALUES(?, ?, ?, ?)",
                        tconst, primaryTitle, startYear, genres
                    )
