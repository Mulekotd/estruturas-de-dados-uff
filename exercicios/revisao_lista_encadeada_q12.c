#include "TLSE/TLSE.h"

void ordena(TLSE *l)
{
    TLSE* p;

    for (p = l; p != NULL; p = p->prox) {
        TLSE* q;

        for (q = p->prox; q != NULL; q = q->prox)
        {
            if (q->info < p->info)
            {
                int tmp = p->info;
                p->info = q->info;
                q->info = tmp;
            }
        }
    }
}
