#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // int i = get_int("i: ");
    // int j = get_int("j: ");

    // if (i == j) {
    //     printf("Same\n");
    // } else {
    //     printf("Different\n");
    // }

    string s = get_string("s: ");
    string t = get_string("t: ");

    printf("%p\n", s);
    printf("%p\n", t);

    if (s == t) {
        printf("Same\n");
    } else {
        printf("Differnent\n");
    }

   return 0;
}
