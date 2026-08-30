#include "TAB/TAB.h"

TAB* menor(TAB *a)
{
    TAB* menorEsq;
    TAB* menorDir;
    TAB* menorNo;

    if (!a)
        return NULL;

    menorEsq = menor(a->esq);
    menorDir = menor(a->dir);
    menorNo = a;

    if (menorEsq && menorEsq->info < menorNo->info)
        menorNo = menorEsq;

    if (menorDir && menorDir->info < menorNo->info)
        menorNo = menorDir;

    return menorNo;
}
