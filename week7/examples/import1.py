from csv import DictReader, writer


with open("srcdata/title.basics.tsv", "r") as titles:
    reader = DictReader(titles, delimiter="\t")

    # Create subsets of source data: Extract only tvShow
    with open("show1.csv", "w") as shows:
        writer = writer(shows)

        writer.writerow(["tconst", "primaryTitle", "startYear", "genres"])
        for row in reader:
            if row["startYear"] == "\\N":
                # Continue to start of loop
                continue

            year = int(row["startYear"])
            if year < 1970:
                continue

            if row["titleType"] == "tvSeries" and row["isAdult"] == "0":
                writer.writerow([row["tconst"], row["primaryTitle"], row["startYear"], row["genres"]])
