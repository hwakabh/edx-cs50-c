#include <stdio.h>
#include <unistd.h>

int main()
{
    // Starting closed-loop for showing up overflow
    // ---> 1, 2, 4, ... , 1073741824, -2147483648, 0, 0, 0 ...
    for (int i = 1; ; i *= 2) {
        printf("%d\n", i);
        sleep(1);
    }

    // --- Case if not using for, same as below:
    // int i = 1;
    // while(1) {
    //     printf("%d\n", i);
    //     i *= 2;
    //     sleep(1);
    // }

    return 0;
}
