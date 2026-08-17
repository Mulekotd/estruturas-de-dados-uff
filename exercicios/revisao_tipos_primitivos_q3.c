#include <stdio.h>

// Primeira implementação: ponteiro do relógio passando os minutos O(n)
// int getMinutesFromHour(int h1, int m1, int h2, int m2)
// {
//     // Caso trivial: Passaram-se 24h
//     if (h1 == h2 && m1 == m2)
//         return 1440;
    
//     int elapsed = 0;

//     // Condição de parada (h1 == h2) && (m1 == m2)
//     while ((h1 != h2) || (m1 != m2)) 
//     {
//         if (m1 == 60)
//         {
//             m1 = 0;
//             h1++;

//             if (h1 == 24)
//                 h1 = 0;
//         }

//         m1++;
//         elapsed++;
//     }

//     return elapsed;
// }

// Segunda implementação: aritmética O(1)
int getMinutesFromHour(int h1, int m1, int h2, int m2)
{
    int hour = h1 * 60 + m1;
    int alarm = h2 * 60 + m2;

    if (alarm <= hour)
        alarm += 24 * 60;

    return alarm - hour;
}

int main(void)
{
    while (1)
    {
        int h1, m1, h2, m2;
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
    
        if (h1 == 0 && \
            m1 == 0 && \
            h2 == 0 && \
            m2 == 0) break;
        
        printf("%d\n", getMinutesFromHour(h1, m1, h2, m2));
    }

    return 0;
}
