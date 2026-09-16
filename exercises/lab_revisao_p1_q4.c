/* Faça uma função que retorne todos os caminhos que somam N em uma TAB.
Um caminho deve começar a partir da raiz e terminar em uma folha. */

#include "TAB/TAB.h"

void conta_caminhos_aux(TAB *a, int N, int *soma_atual, int *caminhos) {
    if (a == NULL)
        return;

    (*soma_atual) += a->info;
    
    if ((a->esq == NULL) && (a->dir == NULL)) {
        if (*soma_atual == N)
            (*caminhos)++;
    }

    conta_caminhos_aux(a->esq, N, soma_atual, caminhos);
    conta_caminhos_aux(a->dir, N, soma_atual, caminhos);
    
    (*soma_atual) -= a->info;
}

int conta_caminhos(TAB *a, int N) {
    if (a == NULL)
        return 0;

    int soma_atual = 0, caminhos = 0;

    conta_caminhos_aux(a, N, &soma_atual, &caminhos);

    return caminhos;
}
