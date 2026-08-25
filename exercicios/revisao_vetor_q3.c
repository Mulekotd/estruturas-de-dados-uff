#include <stdio.h>
#include <stdlib.h>

static int getDigits(int n)
{
    int count = 0;

    while (n != 0)
    {
        n /= 10;
        count++;
    }

    return count;
}

static int *numberToArray(int n, int digits)
{
    if (digits <= 0)
        return NULL;

    int* aux = (int*) calloc(digits, sizeof(int));

    for (int i = digits - 1; i >= 0; i--)
    {
        aux[i] = n % 10;
        n /= 10;
    }

    return aux;
}

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    
    int digitsA = getDigits(a);
    int digitsB = getDigits(b);

    if (digitsA != digitsB)
    {
        printf("Não é permutação.\n");
        return -1;
    }

    int* arrayA = numberToArray(a, digitsA);
    int* arrayB = numberToArray(b, digitsB);

    int occurrences[10] = {0};

    for (int i = 0; i < digitsA; i++)
    {
        occurrences[arrayA[i]]++;
        occurrences[arrayB[i]]--;
    }

    for (int digit = 1; digit <= 9; digit++)
    {
        if (occurrences[digit] != 0)
        {
            printf("Não é permutação.\n");

            free(arrayA);
            free(arrayB);

            return 0;
        }
    }

    printf("É permutação.\n");

    free(arrayA);
    free(arrayB);

    return 0;
}
