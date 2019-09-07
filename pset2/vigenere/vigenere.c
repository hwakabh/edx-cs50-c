#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int is_valid_input(char input[])
{
    int key_len = strlen(input);
    for (int i = 0; i < key_len; i++) {
        if (!isalpha(input[i])) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc == 1) {
        printf("Please provide encryption keywords.\n");
        printf("Usage : ./vigenere <ENCRYPT_KEYWORDS>\n");
        return 1;
    } else if (argc >= 3) {
        printf("Please provide just one key.\n");
        return 1;
    }

    // Escaping cases if keyword contains charactors
    int is_valid = is_valid_input(argv[1]);
    if (is_valid == 1) {
        printf("Providing numbers as keyword not supporting, expected charactors.\n");
        return 1;
    }

    return 0;
}