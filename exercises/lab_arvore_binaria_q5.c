// Retorne o nó de maior nível que é ancestral tanto de N quanto de M.

#include "TAB/TAB.h"

TAB* maior_nivel(TAB *a, int N, int M) {
    if (a == NULL)
        return NULL;

    // Se N e M são menores que o valor do nó atual,
    // o ancestral comum está na subárvore esquerda
    if (N < a->info && M < a->info)
        return maior_nivel(a->esq, N, M);

    // Se N e M são maiores, está na subárvore direita
    if (N > a->info && M > a->info)
        return maior_nivel(a->dir, N, M);

    return a;
}
