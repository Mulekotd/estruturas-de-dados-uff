#include "TAB/TAB.h"

int ni(TAB *a)
{
    if (!a)
        return 0;

    /* Nó interno possui pelo menos um filho */
    if (!a->esq && !a->dir)
        return 0;

    return 1 + ni(a->esq) + ni(a->dir);
}
