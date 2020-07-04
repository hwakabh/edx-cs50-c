#include <stdio.h>   // printf()
#include <cs50.h>   // get_int()

void draw(int h);


int main(void)
{
    int height = get_int("Height: ");

    draw(height);
    return 0;
}


void draw(int h)
{
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= i; j++) {
            printf("#");
        }
        printf("\n");
    }
}
