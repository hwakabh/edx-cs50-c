#include <stdio.h>
#define MAX 9       // Maximun numbers of candidates

typedef struct {
    const char *name;
    int votes;
} candidate;

int vote(const char *n);
void print_winner(candidate cands);


int main(int argc, char *argv[])
{
    // --- Check inputs from command line
    // If argc < 2, return 1 and exit program with printing usage
    if (argc < 2) {
        printf("Usage: ./plurality [candidate ...]\n");
        return 1;
    }
    // If numbers of candidates given by argv, return 2 and exit program
    int num_candidates = argc - 1;
    if (num_candidates > MAX) {
        printf("Maximum number of candidates is %d\n", MAX);
        return 2;
    }

    return 0;
}


int vote(const char *n)
{
    // Functions to update candidates[].votes, if matches the name
}

void print_winner(candidate cands)
{
    // Functions to member(s) whose vote is biggest
    // -- If tie-case, print all the winners
}
