from csv import DictReader

# Same as `counts = dict()` for declaration of dictionary
counts = {}

with open("./srcdata/names.basic.min.tsv", "r") as file:
    # Use tab-separater since the source file is .tsv format intead of csv
    reader = DictReader(file, delimiter="\t")
    
    for row in reader:
        # Standardize data with forcely lowerize
        title = row["primaryName"].lower()

        if title in counts:
            counts[title] += 1
        else:
            counts[title] = 1


# Lambda function: for sort with values in dictionary,
# required to implement function that returns value
def f(item):
    return item[1]

# print out results with alphabetically sorted & lambda function
# Sort with values in dict:counts
for title, count in sorted(counts.items(), key=f, reverse=True):
    # Align to SQLite format
    print(title, count, sep=" | ")


# Case if using `lambda` statements
for title, count in sorted(counts.items(), key=lambda item: item[1], reverse=True):
    print(title, count, sep=" | ")
