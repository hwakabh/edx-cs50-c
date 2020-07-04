#include <stdio.h>    // printf()
#include <cs50.h>     // get_int()

void draw(int h);


int main(void)
{
    int height = get_int("Height: ");
    draw(height);
}

void draw(int h)
{
    // Base case
    if (h == 0) {
        return;
    }

    // Call function itself
    draw(h - 1);

    for (int i = 0; i < h; i++) {
        printf("#");
    }
    printf("\n");
}
