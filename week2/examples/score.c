#include <stdio.h>

float average(int length, int array[]);

int main()
{
    // Prompt user for numbers of array
    int n;
    printf("Numbers of scores: ");
    scanf("%d", &n);

    int scores[n];
    for (int i = 0; i < n; i++) {
        int m;
        printf("Score %d: ", i + 1);
        scanf("%d", &m);
        scores[i] = m;
    }

    printf("Average : %.1f\n", average(n, scores));

    return 0;
}


float average(int length, int array[])
{
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += array[i];
    }
    return (float) sum / (float) length;
}
