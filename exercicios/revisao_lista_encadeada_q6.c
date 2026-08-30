#include "TLSE/TLSE.h"

TLSE* i_p(TLSE *l)
{
    TLSE* resultado = NULL;
    TLSE** fim = &resultado;
    TLSE* p;

    for (p = l; p != NULL; p = p->prox)
    {
        if (p->info % 2 != 0)
        {
            *fim = (TLSE *) malloc(sizeof(TLSE));
            (*fim)->info = p->info;
            (*fim)->prox = NULL;
            fim = &(*fim)->prox;
        }
    }

    for (p = l; p != NULL; p = p->prox)
    {
        if (p->info % 2 == 0)
        {
            *fim = (TLSE *) malloc(sizeof(TLSE));
            (*fim)->info = p->info;
            (*fim)->prox = NULL;
            fim = &(*fim)->prox;
        }
    }

    return resultado;
}
