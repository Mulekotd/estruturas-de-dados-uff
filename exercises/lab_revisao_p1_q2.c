// Faça uma função que verifique se uma TAB é simétrica.

#include "TAB/TAB.h"

int eh_simetrico_aux(TAB *esq, TAB *dir) {
    if (esq == NULL && dir == NULL)
        return 1; // É simétrica

    if (esq == NULL || dir == NULL)
        return 0; // Subarvores de tamanho diferente

    if (esq->info != dir->info)
        return 0; // Não é simétrica 

    return eh_simetrico_aux(esq->esq, dir->dir) &&
           eh_simetrico_aux(esq->dir, dir->esq);
}

int eh_simetrico(TAB *a) {
    if (a == NULL)
        return 1;

    return eh_simetrico_aux(a->esq, a->dir);
}