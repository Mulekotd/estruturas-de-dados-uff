// Faça uma função que conte TODOS os caminhos entre dois vértices de um grafo.

#include "TG/TG.h"
#include "TLSE.h"

void conta_caminho_aux(TG *g, int atual, int destino, int *caminhos, TLSE **visitados) {
    *visitados = TLSE_insere(*visitados, atual);

    // Caso base: achou o destino
    if (atual == destino) {
        (*caminhos)++;
        *visitados = TLSE_retira(*visitados, atual);
        return;
    }

    TG *no = TG_busca_no(g, atual);

    if (no == NULL) {
        *visitados = TLSE_retira(*visitados, atual);
        return;
    }

    TVIZ *v = no->prim_viz;

    while (v) {
        if (!TLSE_busca(*visitados, v->id_viz)) {
            conta_caminho_aux(g, v->id_viz, destino, caminhos, visitados);            
        }

        v = v->prox_viz;
    }

    *visitados = TLSE_retira(*visitados, atual);
}

int conta_caminho(TG *g, int id_inicio, int id_fim) {
    if (!TG_busca_no(g, id_inicio) || !TG_busca_no(g, id_fim))
        return 0;

    TLSE *visitados = NULL;
    int caminhos = 0; 
    
    conta_caminho_aux(g, id_inicio, id_fim, &caminhos, &visitados);

    TLSE_libera(visitados);

    return caminhos;
}
