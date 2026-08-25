#include <stdio.h>
#include <stdlib.h>

int secondMostSuspectIndex(const int* suspects, int size)
{
    int mostSuspect = 0;
    int secondMostSuspect = 1;

    if (suspects[secondMostSuspect] > suspects[mostSuspect])
    {
        mostSuspect = 1;
        secondMostSuspect = 0;
    }

    for (int i = 2; i < size; i++)
    {
        if (suspects[i] > suspects[mostSuspect])
        {
            secondMostSuspect = mostSuspect;
            mostSuspect = i;
        }
        else if (suspects[i] > suspects[secondMostSuspect])
            secondMostSuspect = i;
    }

    return secondMostSuspect + 1;
}

int main(void)
{
    int n;

    while (scanf("%d", &n) == 1 && n != 0)
    {
        int* suspects = malloc(n * sizeof(int));

        if (!suspects)
            return 1;

        for (int i = 0; i < n; i++)
            scanf("%d", &suspects[i]);

        printf("%d\n", secondMostSuspectIndex(suspects, n));

        free(suspects);
    }

    return 0;
}
