#include "arvb.h"

TARVB *TARVB_busca(TARVB *a, int x) {
    if (a = NULL)
        return a;

    int i = 0;

    // Anda horizontalmente
    while ((i < a->nchaves) && (a->chave[i] < x))
        i++;
    
    // Caso base
    if ((i < a->nchaves) && (a->chave[i] == x))
        return a;

    return TARVB_busca(a->filho[i], x);
}

TARVB *TARVB_cria(int t) {
    int i, tam = 2*t;

    TARVB *a = (TARVB *) malloc(sizeof(TARVB));
    a->folha = 1;
    a->nchaves = 0;
    a->chave = (int *) malloc(sizeof(int) * (tam - 1));
    a->filho = (TARVB **) malloc(sizeof(TARVB *) * tam);

    for (i = 0; i < tam; i++) {
        a->filho[i] = NULL;
    }

    return a;
}

void TARVB_libera(TARVB *a) {
    if (a) {
        if (!a->folha) {
            for (int i = 0; i < a->nchaves; i++) {
                TARVB_libera(a->filho);
            }
        }

        free(a->filho);
        free(a->chave);
        free(a);
    }
}

void TARVB_imprime(TARVB *a) {
    if (a == NULL) return;

    int i;

    for (i = 0; i < a->nchaves; i++) {
        TARVB_imprime(a->filho[i]);
        printf("%d ", a->chave[i]);
    }

    TARVB_imprime(a->filho[i]);
}

TARVB *TARVB_suc(TARVB *a, int x) {
    if (a == NULL)
        return a;
    
    return suc_aux(a, x, NULL);
}

TARVB *suc_aux(TARVB *a, int x, TARVB *resp) {
    if (a == NULL)
        return resp;

    int i = 0;

    while ((i < a->nchaves) && (a->chave[i] < x))
        i++;

    if ((i < a->nchaves) && (a->chave[i] == x))
        return suc_aux(a->filho[i+1], x, resp);    

    return suc_aux(a->filho[i], x, a);
}
