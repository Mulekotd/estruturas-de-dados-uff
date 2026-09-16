// Retorne o número de caminhos que somam N em uma árvore binária simples.

#include "TAB/TAB.h"

void conta_caminhos(TAB *a, int N, int soma_atual, int *caminhos) {
    if (!a) return;

    soma_atual += a->info;

    // Verifica se é folha e se a soma bateu
    if (!a->esq && !a->dir) {
        if (soma_atual == N)
            (*caminhos)++;

        return;
    }

    conta_caminhos(a->esq, N, soma_atual, caminhos);
    conta_caminhos(a->dir, N, soma_atual, caminhos);
}

int quant_caminhos(TAB *a, int N) {
    if (!a) return 0;

    int caminhos = 0;
    conta_caminhos(a, N, 0, &caminhos);

    return caminhos;
}
