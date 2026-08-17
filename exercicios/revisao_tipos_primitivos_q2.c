#include <stdio.h>

int isPrime(int number)
{
    if (number < 2)
        return 0;

    for (int i = 2; i < number - 1; i++)
    {
        if (number % i == 0)
            return 0;
    }

    return 1;
}

int main(void)
{
    while (1)
    {
        int n;
        scanf("%d", &n);

        if (n <= 0)
            break;

        int count = 0, candidate = (n + 1);

        while (count < 2)
        {
            if (isPrime(candidate))
            {
                printf("%d ", candidate);
                count++;
            }

            candidate = candidate + 1;
        }

        printf("\n");
    }

    return 0;
}
