#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static int size(int n)
{
    return floor(log10(n)) + 1;
}

static int* numberToArray(int n, int digits)
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

static int isPalindrome(int* n, int digits)
{
    if (digits == 1 || digits == 0)
        return 1;
    
    int palindrome = 1;

    for (int i = 0; i < digits; i++)
    {
        if (n[i] != n[digits - 1 - i])
        {
            palindrome = 0;
            break;
        }
    }

    return palindrome;
}

int main(void)
{
    int n;
    
    while (1)
    {
        scanf("%d", &n);

        if (n < 0)
            break;

        int digits = size(n);
        int* a = numberToArray(n, digits);

        if (isPalindrome(a, digits))
            printf("VERDADEIRO\n");
        else
            printf("FALSO\n");
    }

    return 0;
}
