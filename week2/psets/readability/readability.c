#include <stdio.h>  // printf()
#include <string.h> // strlen()
#include <math.h>   // round() for round-up
#include <cs50.h>   // get_string()

int get_coleman_liau_index(int l, int s, int w);
int count_letters(string p);
int count_sentences(string p);
int count_words(string p);


int main(void)
{
    int grade;
    int lc = 0;
    int wc = 0;
    int sc = 0;

    string paragraph = get_string("Text: ");

    lc = count_letters(paragraph);
    sc = count_sentences(paragraph);
    wc = count_words(paragraph);

    // print results
    // Grade range is between 1 - 16
    // If grade is bigger than 16, print Grade 16+, and if grade is lower than 1, print Before Grade 1
    grade = get_coleman_liau_index(lc, sc, wc);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
    return 0;
}


int count_letters(string p)
{
    int lc = 0;

    int len = strlen(p);
    for (int i = 0; i < len; i++)
    {
        if ((p[i] >= 'A' && p[i] <= 'Z') || (p[i] >= 'a' && p[i] <= 'z') || (p[i] == '0' && p[i] == '9'))
        {
            lc += 1;
        }
    }
    return lc;
}


int count_words(string s)
{
    int wc = 0;

    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if ((s[i] == ' ') && (s[i - 1] != ' '))
        {
            wc += 1;
        }
    }

    return wc + 1;
}


int count_sentences(string p)
{
    int sc = 0;

    int len = strlen(p);
    for (int i = 0; i < len; i++)
    {
        if (p[i] == '.' || p[i] == '!' || p[i] == '?')
        {
            sc += 1;
        }
    }

    return sc;
}


int get_coleman_liau_index(int l, int s, int w)
{
    // Coleman-Liau Index: 0.0588 * L - 0.296 * S - 15.8
    // L: average number of letters per 100 word
    // S: average number of sentences per 100 word

    float index;
    float L = (float) l / (float) w * 100;
    float S = (float) s / (float) w * 100;

    index = 0.0588 * L - 0.296 * S - 15.8;

    return round(index);
}
