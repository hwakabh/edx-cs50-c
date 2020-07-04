#include <stdio.h>      // printf()
#include <string.h>     // strlen()
#include <ctype.h>      // toupper(), tolower(), isalpha()
#include <cs50.h>       // get_string()


int main(int argc, string argv[])
{
    // Validate number of command line arguments
    if (argc == 1 || argc >= 3)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Validate provided key is 26 chars or not
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int x = 0; x < 26; x++)
    {
        // Validate provided key is all alphabet or not
        if (isalpha(argv[1][x]) == 0)
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }

        // Validate key has duplicated value or not
        for (int y = 0; y < 26; y++)
        {
            if (x != y && argv[1][x] == argv[1][y])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    // Start to get input
    string plaintext = get_string("plaintext: ");
    int len = strlen(plaintext);

    printf("ciphertext: ");
    for (int i = 0; i < len; i++)
    {
        if (plaintext[i] == '\0')
        {
            break;
        }
        unsigned char c;
        int offset;
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            offset = plaintext[i] - 97;
            c = tolower(argv[1][offset]);
        }
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            offset = plaintext[i] - 65;
            c = toupper(argv[1][offset]);
        }
        else
        {
            c = plaintext[i];
        }
        printf("%c", c);

    }
    printf("\n");
    return 0;
}
