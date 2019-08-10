#include <stdio.h>

void print_blocks(int num);

int main(void)
{

    // Get height of blocks
    int h;
    printf("Height : ");
    scanf("%d", &h);

    for ( int i = 0; i < h; i++)
    {
        print_blocks(i + 1);
    }

    return 0;
}

void print_blocks(int num)
{
    for (int j = 0; j < num; j++)
    {
        printf("#");
    }
    printf("\n");
}