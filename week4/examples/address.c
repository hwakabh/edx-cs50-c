#include <stdio.h>

int main(void)
{
    int n = 50;
    // & means addressOf
    printf("%p\n", &n);
    // * in references means goTo
    printf("%i\n", *&n);

    int *p = &n;
    printf("%p\n", p);
    printf("%i\n", *p);

    // string and pointers
    char *s = "EMMA";
    // printf() with %s: means loop each char until null terminator
    printf("%s\n", s);
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);

    printf("%c\n", *s);
    // pointer arithmetic
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
    printf("%c\n", *(s + 3));

    return 0;
}
