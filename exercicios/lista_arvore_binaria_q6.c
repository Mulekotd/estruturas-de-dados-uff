#include <stdlib.h>
#include "TAB/TAB.h"

static TAB* anexa_direita(TAB *arv, TAB *subarv)
{
    if (!arv)
        return subarv;

    arv->dir = anexa_direita(arv->dir, subarv);

    return arv;
}

TAB* retira_pares(TAB *arv)
{
    TAB *esq, *dir;

    if (!arv)
        return NULL;

    arv->esq = retira_pares(arv->esq);
    arv->dir = retira_pares(arv->dir);

    if (arv->info % 2 != 0)
        return arv;

    esq = arv->esq;
    dir = arv->dir;

    free(arv);

    if (!esq)
        return dir;

    if (!dir)
        return esq;

    return anexa_direita(esq, dir);
}
