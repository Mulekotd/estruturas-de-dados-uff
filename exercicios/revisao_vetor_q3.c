#include <stdio.h>
#include <stdlib.h>

int getDigits(int number)
{
    int count = 0;

    while (number != 0)
    {
        number /= 10;
        count++;
    }

    return count;
}

int* numberToArray(int number, int size)
{
    int* array = (int*) malloc(sizeof(int) * size);
    
    for (int i = size - 1; i >= 0; i--)
    {
        array[i] = number % 10;
        number /= 10;
    }

    return array;
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

    /*
     * Cada posição representa um dígito. Ao final, a quantidade de cada
     * dígito deve ser a mesma nos dois números.
     */
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
