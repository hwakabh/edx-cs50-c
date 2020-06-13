#include <stdio.h>
#define MAX_LENGTH 256


int main()
{
    char answer[MAX_LENGTH];
    printf("What is your name ?? >>> ");
    scanf("%s", answer);

    // Print user input with placeholders
    printf("hello, %s\n", answer);

    // --- More: case for using multiple placeholders
    int age;
    printf("What is your age ?? >>> ");
    scanf("%d", &age);
    printf("hello, %s. you are %d old age.\n", answer, age);

    return 0;
}