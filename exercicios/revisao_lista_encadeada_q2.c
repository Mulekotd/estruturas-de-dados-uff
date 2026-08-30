#include "TLSE/TLSE.h"

TLSE* inverte(TLSE *l)
{
    if (l == NULL || l->prox == NULL)
        return l;

    TLSE* nova_cabeca = inverte(l->prox);

    l->prox->prox = l;
    l->prox = NULL;

    return nova_cabeca;
}
