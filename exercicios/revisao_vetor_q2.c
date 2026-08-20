#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int g;
    int* v;

    while (1)
    {
        scanf("%d", &g);
        
        if (g == 0)
            break;
    }

    free(v);

    return 0;
}
