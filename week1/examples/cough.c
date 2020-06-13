#include <stdio.h>

// Function prototypes
void cough(int n);

int main()
{
    // Logically same as (int i = 1; i <= 3; i++)
    cough(3);
    return 0;
}


void cough(int n)
{
    // Parameterize the function
    for (int i = 0; i < n; i++) {
        printf("cough\n");
    }
}
