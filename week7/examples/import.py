from csv import DictReader, writer


with open("srcdata/title.basics.tsv", "r") as titles:
    reader = DictReader(titles, delimiter="\t")

    # Create subsets of source data: Extract only tvShow
    with open("show0.csv", "w") as shows:
        writer = writer(shows)

        writer.writerow(["tconst", "primaryTitle", "startYear", "genres"])

        for row in reader:
            if row["titleType"] == "tvSeries" and row["isAdult"] == "0":
                writer.writerow([row["tconst"], row["primaryTitle"], row["startYear"], row["genres"]])
