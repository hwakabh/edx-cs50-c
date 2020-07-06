import re
from cs50 import get_string


def main():
    text = get_string("Text: ")

    letters = [c for c in text if c.isalpha()]
    # print(f"Letters: {len(letters)}")

    words = text.split()
    # print(f"Words: {len(words)}")

    sentences = re.split(r"[.!?]\s", text)
    # print(f"Sentences: {len(sentences)}")


    # Get grade & print results
    grade = get_coleman_liau_index(
        l=len(letters),
        w=len(words),
        s=len(sentences)
    )
    if grade < 1:
        print("Before Grade 1")
    elif grade > 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")


def get_coleman_liau_index(l, w, s):
    L = l / w * 100
    S = s / w * 100
    index = 0.0588 * L - 0.296 * S - 15.8
    return round(index)


main()