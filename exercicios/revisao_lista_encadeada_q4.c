#include "TLSE/TLSE.h"

TLSE* copia(TLSE *l)
{
    TLSE* nova = NULL;
    TLSE** fim = &nova;

    while (l != NULL)
    {
        *fim = (TLSE *) malloc(sizeof(TLSE));
        (*fim)->info = l->info;
        (*fim)->prox = NULL;
        fim = &(*fim)->prox;
        l = l->prox;
    }

    return nova;
}
