/* Faça uma função que encontre todos os elementos maiores que N em uma ABB
e retorne num vetor ordenado; não utilize nenhum algoritmo de ordenação. */

#include "TABB/TABB.h"

// Conta quantos elementos são maiores que N
int conta_maiores(TABB *a, int N) {
    if (a == NULL)
        return 0;

    if (a->info > N)
        return conta_maiores(a->esq, N) + 1 + conta_maiores(a->dir, N);
    else // se info <= N, esquerda toda é <= N também
        return conta_maiores(a->dir, N);
}

void maiores_rec(TABB *a, int N, int *vetor, int *i) {
    if (a == NULL)
        return;

    if (a->info > N) {
        maiores_rec(a->esq, N, vetor, i);
        vetor[*i] = a->info;
        (*i)++;
        maiores_rec(a->dir, N, vetor, i);
    } else {
        maiores_rec(a->dir, N, vetor, i);
    }
}

int *maioresN(TABB *a, int N, int *tam_vet) {
    *tam_vet = conta_maiores(a, N);

    if (*tam_vet == 0)
        return NULL;

    int *vetor = (int *) malloc((*tam_vet) * sizeof(int));
    int i = 0;

    maiores_rec(a, N, vetor, &i);

    return vetor;
}
