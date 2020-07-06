// Implements a dictionary's functionality
#include <stdio.h>        // fopen(), FILE
#include <stdbool.h>      // bool, true, false
#include <string.h>       // strcpy(), strcmp()
#include <strings.h>      // strcasecmp()
#include <stdlib.h>       // malloc()
#include <ctype.h>        // tolower()

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table: alphabetical index
const unsigned int N = 26;
// Word counts in dictionary
int count = 0;

// Hash table & its pointer to access
node *table[N];
node *cursor;


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Get index of target word for access hash table
    int index = hash(word);
    cursor = table[index]->next;

    while (cursor != NULL) {
        // Find the word between hash-table
        if (strcasecmp(cursor->word, word) == 0) {
            return true;
        }
        // Update pointer if could not found
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Get first letter of word
    char capital = tolower(word[0]);
    // Get the index of capital letter, a=97 in ASCII
    int index = capital - 97;
    return index;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    // checking result, if failed to open file, fopen() returns NULL
    if (file == NULL) {
        return false;
    }
    // First elements of Hash Table
    for (int i = 0; i < N; i++) {
        node *words = malloc(sizeof(node));
        if (words == NULL) {
            return false;
        }

        words->next = NULL;
        table[i] = words;
    }

    char bf[LENGTH + 1];
    int index = 0;
    // If reached End Of File, break the closed-loop
    while(fscanf(file, "%s", bf) != EOF) {
        // Reserve memory space for storing each word
        node *words = malloc(sizeof(node));
        if (words == NULL) {
            return false;
        }

        // Insert node into hash table with hashed value
        strcpy(words->word, bf);
        index = hash(words->word);
        words->next = table[index]->next;
        table[index]->next = words;
        count++;
    }

    // If reached EOF, close file-pointer
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // Start loops for each elements in hash-table
    for (int i = 0; i < N; i++) {
        // Pointer to elements to release memory
        cursor = table[i];
        // Start loops for each elements in array as one of elements of hash-table
        while (cursor != NULL) {
            // Copy address to release target elements
            node *tmp = cursor;
            // Update pointer for next elements in hash-table
            cursor = cursor->next;
            // Release memory
            free(tmp);
        }
    }
    // If successfully released all memory, returns true
    return true;
}
