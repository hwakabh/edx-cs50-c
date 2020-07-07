from csv import reader
from sys import argv, exit


def main():
    # Validations of command line arguments
    if len(argv) != 3:
        print("Missing command line arguments.\n")
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)
    else:
        # Also checking file extensions
        if argv[1][-4:] != '.csv' or argv[2][-4:] != '.txt':
            print("Provided file(s) are invalid.")
            exit(1)

    # Load csv file
    with open(argv[1], "r") as f:
        lines = [line for line in reader(f)]

    # Load DNA sequences text
    with open(argv[2], "r") as f:
        dnaseq = f.read()

    patterns = {}
    for i in lines[0][1::]:
        patterns[i] = [0]

    # Loop with every STR and check patterns exists with sequentially
    for ptrn in patterns.keys():
        l = len(ptrn)
        start = 0
        for i in range(len(dnaseq)):
            end = i + l
            if end >= len(dnaseq):
                break
            elif ptrn == dnaseq[i:end]:
                patterns[ptrn][-1] += 1
                start = 1
            elif 0 < start < l:
                start += 1
            else:
                start = 0
                patterns[ptrn].append(0)

    matches = [max(v) for v in patterns.values()]

    # Check who is equal to matched patterns
    for person in lines[1:]:
        if [int(i) for i in person[1:]] == matches:
            print(person[0])
            exit(0)

    # Case if nobody matches
    print("No match")
    exit(0)


main()