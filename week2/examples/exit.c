#include <stdio.h>


int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Missing command-line arugment.\n");
        printf("Usage: %s [ args ]\n", argv[0]);
        return 1;
    }

    printf("hello, %s\n", argv[1]);
    return 0;
}
