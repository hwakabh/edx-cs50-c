#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
    char *s = get_string("s: ");

    // // copyting the address
    // char *t = s;
    // t[0] = toupper(t[0]);

    // Reserve the memory for string:t
    // malloc returns pointer of address reserved
    char *t = malloc(strlen(s) + 1);

    // Copy entire elements, including null-terminator: same as strcpy(t_address, s_address)
    for (int i = 0, l = strlen(s); i < l + 1; i++) {
        t[i] = s[i];
    }

    t[0] = toupper(t[0]);
    printf("%s\n", s);
    printf("%s\n", t);

    free(t);

    return 0;
}
