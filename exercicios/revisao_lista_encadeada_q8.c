#include "TLSE/TLSE.h"

int igual(TLSE *l1, TLSE *l2)
{
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->info != l2->info)
            return 0;

        l1 = l1->prox;
        l2 = l2->prox;
    }

    return l1 == NULL && l2 == NULL;
}
