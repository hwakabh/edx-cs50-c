#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 1) {
        printf("Please provide encryption key numbers.\n");
        printf("Usage : ./caeser <ENCRYPT_KEY_NUMBER>\n");
        return 1;
    } else if (argc >= 3) {
        printf("Please provide just one key.\n");
        return 1;
    }

    int key = atoi(argv[1]);
    char plaintext[256];
    printf("Enter plaintext : ");
    scanf("%[^\n]", plaintext);

    printf("Ciphertext : ");
    for (int i = 0; i < 256; i++) {
        if (plaintext[i] == '\0') {
            break;
        }
        unsigned char c = plaintext[i] + key;
        if (122 < c) {
            c = ((c - 122) % 26) + 'a' - 1;
        } else if (90 < c && c < 97) {
            c = ((c - 90) % 26) + 'A' - 1; 
        // Case for space included
        } else if (c == 42) {
            c = 32;
        }
        printf("%c", c);
    }
    printf("\n");

    return 0;

}
