/* Se esta estrutura tivesse um campo cor (int cor) na estrutura de grafo,
teste se nós vizinhos não têm a mesma cor.
A função retorna um se os vizinhos não têm a mesma cor e zero, caso contrário. */

#include "TLSE/TLSE.h"

typedef struct viz {
    int id_viz;
    struct viz *prox_viz;
} TVIZ;

typedef struct grafo {
    int id_no, cor;
    struct grafo *prox_no;
    struct viz *prim_viz;
} TG;

TG *TG_busca_no(TG *g, int x) {
    if (!g || g->id_no == x)
        return g;

    return TG_busca_no(g->prox_no, x);
}

void nao_tem_mesma_cor_aux(TG *g, TG *cabeca, int *flag, TLSE **visitados) {
    if (g == NULL || *flag == 0)
        return;

    TVIZ *v = g->prim_viz;

    while (v) {
        // Só verifica a aresta se o vizinho ainda não foi processado
        if (!TLSE_busca(*visitados, v->id_viz)) {
            TG *no = TG_busca_no(cabeca, v->id_viz);

            if (no && no->cor == g->cor) {
                *flag = 0;
                return;
            }
        }

        v = v->prox_viz;
    }

    // Agora o vértice atual foi completamente processado
    *visitados = TLSE_insere(*visitados, g->id_no);

    nao_tem_mesma_cor_aux(g->prox_no, cabeca, flag, visitados);
}

int nao_tem_mesma_cor(TG *g) {
    int flag = 1;

    TLSE *visitados = TLSE_inicializa();

    nao_tem_mesma_cor_aux(g, g, &flag, &visitados);

    TLSE_libera(visitados);

    return flag;
}
