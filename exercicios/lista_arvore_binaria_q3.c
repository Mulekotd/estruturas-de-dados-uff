#include "TAB/TAB.h"

TAB* maior(TAB *a)
{
    TAB* maiorEsq;
    TAB* maiorDir;
    TAB* maiorNo;

    if (!a)
        return NULL;

    maiorEsq = maior(a->esq);
    maiorDir = maior(a->dir);
    maiorNo = a;

    if (maiorEsq && maiorEsq->info > maiorNo->info)
        maiorNo = maiorEsq;

    if (maiorDir && maiorDir->info > maiorNo->info)
        maiorNo = maiorDir;

    return maiorNo;
}