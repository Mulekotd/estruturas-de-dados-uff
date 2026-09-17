/* Faça uma função que encontre todos os elementos menores que N em uma ABB
e os retorne em um vetor ordenado; não utilize nenhum algoritmo de ordenação. */

#include "TABB/TABB.h"

// Conta quantos elementos são menores que N
int conta_menores(TABB *a, int N) {
    if (a == NULL)
        return 0;

    if (a->info < N)
        return conta_menores(a->esq, N) + 1 + conta_menores(a->dir, N);
    else // se info >= N, direita toda é >= N também
        return conta_menores(a->esq, N);
}

// Preenche o vetor em ordem crescente usando índice compartilhado
void menores_rec(TABB *a, int N, int *vetor, int *i) {
    if (a == NULL)
        return;

    if (a->info < N) {
        menores_rec(a->esq, N, vetor, i);
        vetor[*i] = a->info;
        (*i)++;
        menores_rec(a->dir, N, vetor, i);
    } else {
        menores_rec(a->esq, N, vetor, i);
    }
}

int *menoresN(TABB *a, int N, int *tam_vet) {
    *tam_vet = conta_menores(a, N);

    if (*tam_vet == 0)
        return NULL;

    int *vetor = (int *) malloc((*tam_vet) * sizeof(int));
    int i = 0;

    menores_rec(a, N, vetor, &i);

    return vetor;
}
