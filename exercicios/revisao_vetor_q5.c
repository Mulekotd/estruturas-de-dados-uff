#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static int arrayToInteger(int *a, int size)
{
    int value = 0;
    int expoent = 1;

    for (int i = size - 1; i >= 0; i--)
    {
        value += a[i] * expoent;
        expoent *= 10;
    }

    return value;
}

static int bits(int n)
{
    if (n == 0)
        return 1;

    return (int) floor(log2(n)) + 1;
}

static int integerToBinary(int n, int size)
{
    if (n == 0)
        return 0;

    int* b = (int*) calloc(size, sizeof(int));

    if (!b)
        return -1;

    int i = size - 1;

    while (n)
    {
        b[i] = n % 2;
        n /= 2;
        i--;
    }

    int result = arrayToInteger(b, size);

    free(b);

    return result;
}

int main(void)
{
    int n;

    while (1)
    {
        if (scanf("%d", &n) != 1)
            break;

        if (n < 0)
            break;
        
        printf("Binary: %d\n", integerToBinary(n, bits(n)));
    }

    return 0;
}
