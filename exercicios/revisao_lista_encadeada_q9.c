#include "TLSE/TLSE.h"

TLSE* junta_listas(TLSE *l1, TLSE *l2)
{
    TLSE* fim;

    if (l1 == NULL)
        return l2;
    
    fim = l1;

    while (fim->prox != NULL)
        fim = fim->prox;

    fim->prox = l2;

    return l1;
}
