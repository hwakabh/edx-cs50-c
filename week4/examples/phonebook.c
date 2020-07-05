#include <stdio.h>
#include <cs50.h>


int main(void)
{
    // Open file
    FILE *file = fopen("phonebook.csv", "a");

    // Print (write) to file opened
    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    fprintf(file, "%s,%s\n", name, number);
    fclose(file);

    return 0;
}
