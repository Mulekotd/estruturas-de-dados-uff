#include "TARVB/TARVB.h"

TARVB* espelha(TARVB *a, int t) {
    if (!a) return NULL;

    TARVB *aux = TARVB_Cria(t);
    aux->nchaves = a->nchaves;
    aux->folha = a->folha;

    /* Inverte as chaves dentro do nó. */
    for (int i = 0; i < a->nchaves; i++)
        aux->chave[i] = a->chave[a->nchaves - 1 - i];

    /* Inverte a ordem dos nchaves + 1 filhos. */
    if (!a->folha) {
        for (int i = 0; i <= a->nchaves; i++)
            aux->filho[i] = espelha(a->filho[a->nchaves - i], t);
    }

    return aux;
}
