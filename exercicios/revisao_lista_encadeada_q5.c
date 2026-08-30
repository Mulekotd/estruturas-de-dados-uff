#include "TLSE/TLSE.h"

TLSE* rto(TLSE *l, int elem)
{
    TLSE** atual = &l;

    while (*atual != NULL)
    {
        if ((*atual)->info == elem)
        {
            TLSE* removido = *atual;
            *atual = removido->prox;

            free(removido);
        } else
        {
            atual = &(*atual)->prox;
        }
    }

    return l;
}
