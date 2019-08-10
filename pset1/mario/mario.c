#include <stdio.h>

void print_blocks(int num);

const int NUM_LIMIT = 23;
// TODO: Gap string should be used as const

int main(void)
{
    int height;
    do {
        printf("Height : ");
        scanf("%d", &height);
        printf("\n");
    } while (height > NUM_LIMIT || height < 0);

    // Drawing per line
    for (int i = 0; i < height; i++) {
        // Left blocks
        int blanks = height - i - 1;
        for (int b = 0; b < blanks; b++) {
            printf(" ");
        }
        print_blocks(i + 1);
        // Gaps
        printf("|  |");
        // Right blocks
        print_blocks(i + 1);
        printf("\n");
    }
    return 0;
}

void print_blocks(int num)
{
    for (int j = 0; j < num; j++) {
        printf("#");
    }
}
