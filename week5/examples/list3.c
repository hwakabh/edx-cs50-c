// Implementations of linked-list(singly-linked-list)

#include <stdio.h>    // printf()
#include <stdlib.h>   // malloc(), free()

typedef struct node {
    int number;
    struct node *next;
} node;


int main(void)
{
    // List of size 0
    node *list = NULL;

    // Add numbers to list
    node *n = malloc(sizeof(node));
    if (n == NULL) {
        return 1;
    }
    n->number = 1;
    n->next = NULL;
    list = n;     // replace NULL in list with address of n

    // Add numbers to list
    n = malloc(sizeof(node));
    if (n == NULL) {
        return 1;
    }
    n->number = 2;
    n->next = NULL;
    list->next = n;

    // Add numbers to list
    n = malloc(sizeof(node));
    if (n == NULL) {
        return 1;
    }
    n->number = 3;
    n->next = NULL;
    list->next->next = n;

    // Print list
    for (node *tmp = list; tmp != NULL; tmp = tmp->next) {
        printf("%i\n", tmp->number);
    }

    // Free list
    while (list != NULL) {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
}
