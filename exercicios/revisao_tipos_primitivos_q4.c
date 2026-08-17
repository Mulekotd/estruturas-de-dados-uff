#include <stdio.h>

// Algoritmo de Euclides recursivo (MDC)
int mdc(int a, int b)
{
    // Caso base
    if (b == 0)
        return a;

    return mdc(b, a % b);
}

int main(void)
{
    int n, f1, f2;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &f1, &f2);
        printf("%d\n", mdc(f1, f2));
    }

    return 0;
}
