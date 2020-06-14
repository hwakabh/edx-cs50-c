#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 256


int main()
{
    char s[N];
    printf("Before : ");
    scanf("%s", &s);

    printf("After : ");
    // Convert to uppercase
    for (int i = 0, n = strlen(s); i < n; i++) {
        printf("%c", toupper(s[i]));
        // if (s[i] >= 'a' && s[i] <= 'z') {
        //     printf("%c", (int) s[i] - 32);
        // } else {
        //     printf("%c", s[i]);
        // }
    }
    printf("\n");


}
