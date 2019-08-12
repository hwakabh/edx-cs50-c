#include <stdio.h>


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

    int key = 12;

    char plaintext[256];
    printf("Enter plaintext : ");
    scanf("%s", plaintext);

    printf("Ciphertext : ");
    for (int i = 0; i < 256; i++) {
        if (plaintext[i] == '\0') {
            break;
        }
        char c = plaintext[i] + key;
        if (c < 65 || 122 < c) {
            printf("Out of ASCII\n");
        }
        printf("%c", c);
    }
    printf("\n");

    return 0;

}
