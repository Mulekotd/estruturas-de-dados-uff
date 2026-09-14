// 4) Faça uma função que encontre todos os elementos menores que N em uma ABB
// e os retorne em um vetor ordenado; não utilize nenhum algoritmo de ordenação. 

#include "TABB/TABB.h"

// Conta quantos elementos são menores que N
int conta_menores(TABB *a, int N) {
    if (!a) return 0;

    if (a->info < N)
        return conta_menores(a->esq, N) + 1 + conta_menores(a->dir, N);
    else // se info >= N, direita toda é >= N também
        return conta_menores(a->esq, N);
}

// Preenche o vetor em ordem crescente usando índice compartilhado
void menores_rec(TABB *a, int N, int *vetor, int *index) {
    if (!a) return;

    if (a->info < N) {
        menores_rec(a->esq, N, vetor, index);
        vetor[*index] = a->info;
        (*index)++;
        menores_rec(a->dir, N, vetor, index);
    } else {
        menores_rec(a->esq, N, vetor, index);
    }
}

int *menoresN(TABB *a, int N, int *tam_vet) {
    *tam_vet = conta_menores(a, N);

    if (*tam_vet == 0)
        return NULL;

    int *vetor = (int *) malloc((*tam_vet) * sizeof(int));
    int index = 0;

    menores_rec(a, N, vetor, &index);

    return vetor;
}
