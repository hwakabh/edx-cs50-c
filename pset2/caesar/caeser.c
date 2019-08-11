#include <stdio.h>


int main(int argc, char *argv[])
{
    if (argc == 1) {
        printf("Please provide encryption key numbers.\n");
        return 1;
    } else if (argc >= 3) {
        printf("Please provide just one key.\n");
        return 1;
    }

    printf("Command line arguments : \n");
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    return 0;

}
