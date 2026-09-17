// Ache a quantidade de arestas de um grafo

#include "TG/TG.h"
#include "TLSE/TLSE.h"

void na_aux(TG *g, int *arestas, TLSE **visitados) {
    if (g == NULL)
        return;

    TVIZ *v = g->prim_viz;

    while (v) {
        if (!TLSE_busca(visitados, v->id_viz))
            (*arestas)++;
        
        v = v->prox_viz;
    }

    // Marca o vértice atual como processado
    *visitados = TLSE_insere(*visitados, g->id_no);

    na_aux(g->prox_no, arestas, visitados);
}

int na(TG *g) {
    int arestas = 0;
    
    TLSE *visitados = TLSE_inicializa();

    na_aux(g, &arestas, &visitados);

    TLSE_libera(visitados);

    return arestas;
}
