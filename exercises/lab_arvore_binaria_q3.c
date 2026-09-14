// 3) Faça uma função que encontre todos os elementos maiores que N
// em uma ABB e retorne num vetor ordenado; não utilize nenhum algoritmo de ordenação.

#include "TABB/TABB.h"

// Conta quantos elementos são maiores que N
int conta_maiores(TABB *a, int N) {
    if (!a) return 0;

    if (a->info > N)
        return conta_maiores(a->esq, N) + 1 + conta_maiores(a->dir, N);
    else // se info <= N, esquerda toda é <= N também
        return conta_maiores(a->dir, N);
}

// Preenche o vetor em ordem crescente usando índice compartilhado
void maiores_rec(TABB *a, int N, int *vetor, int *index) {
    if (!a) return;

    if (a->info > N) {
        maiores_rec(a->esq, N, vetor, index);
        vetor[*index] = a->info;
        (*index)++;
        maiores_rec(a->dir, N, vetor, index);
    } else {
        maiores_rec(a->dir, N, vetor, index);
    }
}

int *maioresN(TABB *a, int N, int *tam_vet) {
    *tam_vet = conta_maiores(a, N);

    if (*tam_vet == 0)
        return NULL;

    int *vetor = (int *) malloc((*tam_vet) * sizeof(int));
    int index = 0;

    maiores_rec(a, N, vetor, &index);

    return vetor;
}
