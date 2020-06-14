#include <stdio.h>      //printf()
#include <string.h>     //strlen()
#define N 256

int main()
{
    char s[N];
    printf("Input : ");
    scanf("%s", &s);

    printf("Output :");
    for (int i = 0, n = strlen(s); i < n; i++) {
        printf("%c", s[i]);
    }
    printf("\n");

    return 0;
}
