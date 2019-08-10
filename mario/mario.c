#include <stdio.h>

void print_blocks(int num);

int main(void)
{

    // Get height of blocks
    int h;
    printf("Height : ");
    scanf("%d", &h);

    print_blocks(h);

    return 0;
}

void print_blocks(int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("#");
    }
    printf("\n");
}