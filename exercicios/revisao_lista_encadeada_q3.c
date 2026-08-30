#include "TLSE/TLSE.h"

TLSE* desloca(TLSE *l, int n)
{
    TLSE* anterior = NULL;
    TLSE* ultimo = l;
    TLSE* nova_cabeca;

    if (l == NULL || l->prox == NULL)
        return l;

    while (ultimo->prox != NULL)
    {
        anterior = ultimo;
        ultimo = ultimo->prox;
    }

    if (n % 2 != 0)
    {
        anterior->prox = NULL;
        ultimo->prox = l;

        return ultimo;
    }

    nova_cabeca = l->prox;
    ultimo->prox = l;
    l->prox = NULL;

    return nova_cabeca;
}
