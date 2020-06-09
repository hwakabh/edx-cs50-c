#define _XOPEN_SOURCE

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc == 1) {
        printf("Usage : ./crack <HASH>\n");
        return 1;
    } else if (argc >= 3) {
        printf("Please provide just one hash.\n");
        printf("Usage : ./crack <HASH>\n");
        return 1;
    }

    // Get salt from hashed password
    char salt[3];
    strncpy(salt, argv[1], 2);

    // Initialize password to guess
    char password[5] = {"\0"};
    const char alphabets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const int charlen = strlen(alphabets);

    // Brute-Forced
    for (int i = 0; i < charlen; ++i) {
        for (int j = 0; j < charlen; ++j) {
            for (int k = 0; k < charlen; ++k) {
                for (int l = 0; l < charlen; ++l) {
                    if (strcmp(crypt(password, salt), argv[1]) == 0) {
                        printf("Password Cracked : %s\n", password);
                        return 0;
                    }
                    password[0] = alphabets[l];
                }
                password[1] = alphabets[k];
            }
            password[2] = alphabets[j];
        }
        password[3] = alphabets[i];
    }

}
