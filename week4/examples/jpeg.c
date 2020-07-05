#include <stdio.h>


int main(int argc, char *argv[])
{
    // Validates number of command line arguments
    if (argc > 2) {
        return 1;
    }

    // Open file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        return 1;
    }

    // Read 3 Bytes from file
    unsigned char bytes[3];
    fread(bytes, 3, 1, file);

    // Check if bytes are 0xff 0xd8 0xff, which are magic numbers of JPEG format
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff) {
        printf("Maybe\n");
    } else {
        printf("No\n");
    }

    fclose(file);

    return 0;
}
