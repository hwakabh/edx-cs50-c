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

    int key = 13;

    char plaintext[256];
    printf("Enter plaintext : ");
    scanf("%s", plaintext);

    printf("Ciphertext : \n");
    for (int i = 0; i < 256; i++) {
        if (plaintext[i] == '\0') {
            break;
        }
        unsigned char c = plaintext[i] + key;
        if (122 < c) {
            c = ((c - 122) % 26) + 'a' - 1;
        } else if (90 < c && c < 97) {
            c = ((c - 90) % 26) + 'A' - 1; 
        }
        printf("Key %d | Plain %c : %d | Cipher %c : %d\n", key, plaintext[i], plaintext[i], c, c);
    }
    printf("\n");

    return 0;

}
