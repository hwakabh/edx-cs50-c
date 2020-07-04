#include <stdio.h>    // printf()
#include <string.h>   // strcmp()

int main(void)
{
    char *names[4] = {"EMMA", "RODRIGO", "BRIAN", "DAVID"};

    // Start linear search with strings
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(names[i], "EMMA") == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}
