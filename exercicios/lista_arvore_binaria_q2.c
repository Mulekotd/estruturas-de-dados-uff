#include "TAB/TAB.h"

TAB* espelho(TAB *a)
{
    TAB *aux;

    if (!a)
        return NULL;

    aux = TAB_cria(a->info, NULL, NULL);

    aux->esq = espelho(a->dir);
    aux->dir = espelho(a->esq);

    return aux;
}
