#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char name[256];
    printf("Enter your full name : ");
    scanf("%[^\n]", name);

    printf("Your Initials : ");

    if (isalpha(name[0]) != 0) {
        printf("%c", toupper(name[0]));
    }

    int nlen = strlen(name);
    for (int i = 0; i < nlen; i++) {
        if (name[i] == ' ' && isalpha(name[i + 1])) {
            printf("%c", toupper(name[i + 1]));
        }
    }
    printf("\n");

    return 0;
}
