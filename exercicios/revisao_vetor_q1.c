#include <stdio.h>
#include <stdlib.h>

void sieve(int *array, int max)
{
    if (max == 0)
        return;

    array[0] = 2;

    int i = 1;
    for (int current = 3; current < max; current++)
    {
        int is_prime = 1;
        for (int j = 0; j < i; j++)
        {
            if (current % array[j] == 0)
            {
                is_prime = 0;
                break;
            }
        }

        if (is_prime)
        {
            array[i] = current;
            i++;
        }
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    int* primes = calloc(n, sizeof(int));

    sieve(primes, n);

    for (int i = 0; i < n && primes[i]; i++) {
        printf("%d ", primes[i]);
    }

    printf("\n");
    free(primes);

    return 0;
}
