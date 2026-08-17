#include <stdio.h>

int main(void)
{
    int n;
    
    while (1)
    {
        scanf("%d", &n);

        if (n <= 0)
            break;
        
        int isPrime = 0;

        for (int i = 2; i <= n; i++)
        {
            isPrime = 1;

            for (int j = 2; j * j <= i; j++)
            {
                if (i % j == 0)
                {
                    isPrime = 0;
                    break;
                }
            }
            
            if (isPrime)
                printf("%d ", i);
        }

        printf("\n");
    }

    return 0;
}
