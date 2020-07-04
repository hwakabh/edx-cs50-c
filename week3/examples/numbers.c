#include <stdio.h>  // printf()


int main(void)
{
    int numbers[6] = {4, 8, 15, 16, 23, 42};

    // Start linear search with numbers
    for (int i = 0; i < 6; i++) {
        if (numbers[i] == 50) {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}
