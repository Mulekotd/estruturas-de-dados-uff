// 1) Faça uma função que some todos os elementos de nível ímpar de uma árvore binária simples
// e subtraia todos os de nível par.

#include "TAB/TAB.h"

static int misc1_aux(TAB *a, int nivel) {
    if (!a) return 0;

    int valor;

    if (nivel % 2 != 0) valor = a->info;
    else valor = -(a->info);

    return valor + misc1_aux(a->esq, nivel + 1) + misc1_aux(a->dir, nivel + 1);
}

int misc1(TAB *a) {
    return misc1_aux(a, 1);
}
