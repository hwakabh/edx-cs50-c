#include <stdio.h>      // printf(), fopen(), fread(), fwrite(), fclose()
#include <stdbool.h>    // bool, true, false


int main(int argc, char *argv[])
{
    // Validate user input
    if (argc != 2) {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open file and validation
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        return 1;
    }

    // Buffer size to read from raw file
    int buffer_size = 512;
    // Flag to check JPEG magic number is found or not
    bool is_header = false;
    // Counters for JPEG files
    int count = 0;
    // Memory space for output file name: 0XX.jpg
    char ftitle[8];

    // Read file per 512 Bytes
    unsigned char buffer[buffer_size];
    // Initialize output jpeg file with null-pointer
    FILE *image = NULL;

    // Start closed-loop until fread return 0 (read provided buffer size)
    while (true) {
        // fread() returns the number of buffers it could read
        int bs = fread(buffer, buffer_size, 1, file);
        if (bs == 0) {
            break;
        }

        // Check jpeg's magic numbers and bitwise arithmetic
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            ((buffer[3] & 0xf0) == 0xe0)) {
            // If detect jpeg header again, close the jpeg file
            if (image != NULL) {
                fclose(image);
                count++;
            }

            // Update filename and write to them
            sprintf(ftitle, "%03i.jpg", count);
            image = fopen(ftitle, "w");
        }

        if (image != NULL) {
            fwrite(buffer, buffer_size, 1, image);
        }
    }

    fclose(image);
    fclose(file);

    return 0;
}
