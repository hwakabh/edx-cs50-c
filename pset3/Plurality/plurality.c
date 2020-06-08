#include <stdio.h>
#include <string.h>
// Maximum numbers of candidates
#define MAX 9

typedef struct {
    const char *name;
    int votes;
} candidate;

candidate candidates[MAX];

// Function prototypes
int vote(char vtr[], int num_cands);
void print_winner(candidate cands[], int num_cands);


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

    // Define arrays of candidates
    for (int i = 0; i < num_candidates; i++) {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // Take numbers of voters
    printf("Number of voters: ");
    int voter_count;
    scanf("%i", &voter_count);

    // Loop over all voters
    for (int j = 0; j < voter_count; j++) {
        printf("Vote: ");
        char voter[256];
        scanf("%s", voter);

        if (vote(voter, num_candidates) != 0) {
            printf("Invalid vote.\n");
        }
        // for (int i = 0; i < num_candidates; i++) {
        //     printf("%s : %d\n", candidates[i].name, candidates[i].votes);
        // }
    }

    // Display winner of election
    print_winner(candidates, num_candidates);

    return 0;
}


int vote(char vtr[], int num_cands)
{
    for (int l = 0; l < num_cands; l++) {
        if (strcmp(vtr, candidates[l].name) == 0) {
            candidates[l].votes += 1;
            return 0;
        }
    }
    return 1;
}

void print_winner(candidate cands[], int num_cands)
{
    int max_vote = 0;
    for (int m = 0; m < num_cands; m++) {
        if (cands[m].votes > max_vote) {
            max_vote = cands[m].votes;
        }
    }

    for (int n = 0; n < num_cands; n++) {
        if (cands[n].votes == max_vote) {
            printf("%s\n", cands[n].name);
        }
    }
    return;
}
