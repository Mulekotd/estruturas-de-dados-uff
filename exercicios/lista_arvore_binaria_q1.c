#include "TAB/TAB.h"

TAB* copia(TAB *a)
{
    TAB *aux;

    if (!a)
        return NULL;

    aux = TAB_cria(a->info, NULL, NULL);

    aux->esq = copia(a->esq);
    aux->dir = copia(a->dir);

    return aux;
}
