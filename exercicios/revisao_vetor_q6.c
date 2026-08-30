#include <stdio.h>
#include <stdlib.h>

int countClonedTickets(const int *tickets, int size, int ticketCount)
{
    int* occurrences = calloc(ticketCount + 1, sizeof(int));

    if (!occurrences)
        return -1;

    int clonedTickets = 0;

    for (int i = 0; i < size; i++)
    {
        occurrences[tickets[i]]++;

        if (occurrences[tickets[i]] == 2)
            clonedTickets++;
    }

    free(occurrences);

    return clonedTickets;
}

int main(void)
{
    int n, m;

    while (scanf("%d %d", &n, &m) == 2 && (n != 0 || m != 0))
    {
        int* tickets = malloc(m * sizeof(int));

        if (!tickets)
            return 1;

        for (int i = 0; i < m; i++)
            scanf("%d", &tickets[i]);

        int clonedTickets = countClonedTickets(tickets, m, n);

        free(tickets);

        if (clonedTickets < 0)
            return 1;

        printf("%d\n", clonedTickets);
    }

    return 0;
}
