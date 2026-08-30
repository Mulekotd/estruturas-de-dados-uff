#include "TLSE/TLSE.h"

TLSE* ordena(TLSE *l)
{
    TLSE* ordenada = NULL;
    TLSE* p;

    for (p = l; p != NULL; p = p->prox)
    {
        TLSE** pos = &ordenada;
        TLSE* novo = (TLSE *) malloc(sizeof(TLSE));

        novo->info = p->info;

        while (*pos != NULL && (*pos)->info <= novo->info)
            pos = &(*pos)->prox;

        novo->prox = *pos;
        *pos = novo;
    }

    return ordenada;
}
