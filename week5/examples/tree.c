#include <stdio.h>    // printf()
#include <stdlib.h>   // malloc()

// Struct tree data-structure
typedef struct node {
    int number;
    struct node *left;
    struct node *right;
} node;

// Function prototypes
int binary_search(node *tree, int n);


int main(void)
{
    // Define numbers
    int number_list[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    
    // Numbers to search
    int target = 50;
    // Flags to check whether binary_search result
    int result = 0;

    // TODO: create tree data-structures & throw to binary_search
    // node *tree;
    // // Run binary search
    // int result = binary_search(tree, target);

    // // Check result
    // if (result == 1) {
    //     printf("Found.\n");
    //     return 1;
    // }
    // printf("Not Found.\n");
    // return 0;
}


int binary_search(node *tree, int n)
{
    // Base Case: case if we could not find number in tree
    if (tree == NULL) {
        return 0;
    // recursive call
    } else if (n < tree->number) {
        return binary_search(tree->left, n);
    } else if (n > tree->number) {
        return binary_search(tree->right, n);
    // Case if we could find number in tree
    } else {
        return 1;
    }
}
