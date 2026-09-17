// Faça uma função que calcula a média simples dos elementos de cada nível de uma árvore binária simples.

#include "TAB/TAB.h"

// soma e conta os nós que estão exatamente em 'nivel' (raiz = nível 0)
static void soma_nivel(TAB *a, int nivel, int *soma, int *qtd) {
    if (a == NULL)
        return;

    if (nivel == 0) {
        *soma += a->info;
        (*qtd)++;
    } else {
        soma_nivel(a->esq, nivel - 1, soma, qtd);
        soma_nivel(a->dir, nivel - 1, soma, qtd);
    }
}

float *media(TAB *a, int *tam_vet) {
    if (a == NULL) {
        *tam_vet = 0;
        return NULL;
    }

    *tam_vet = TAB_altura(a);

    float *vet = (float *) malloc((*tam_vet) * sizeof(float));

    for (int nivel = 0; nivel < (*tam_vet); nivel++) {
        int soma = 0, qtd = 0;
        soma_nivel(a, nivel, &soma, &qtd);
        vet[nivel] = (float) soma / qtd;
    }

    return vet;
}
