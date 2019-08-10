#include <stdio.h>

void print_blocks(int num);

int main(void)
{

    // Get height of blocks
    int h;
    printf("Height : ");
    scanf("%d", &h);
    printf("\n");

    for ( int i = 0; i < h; i++)
    {
        // Left blocks
        int blanks = h - i - 1;
        for (int b = 0; b < blanks; b++)
        {
            printf(" ");
        }
        print_blocks(i + 1);
        // Separate blocks right and left
        printf("|  |");
        // Right blocks
        print_blocks(i + 1);
        printf("\n");
    }

    return 0;
}

void print_blocks(int num)
{
    for (int j = 0; j < num; j++)
    {
        printf("#");
    }
}
