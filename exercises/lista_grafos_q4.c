// Verificar se um grafo possui todos os nós com grau igual a k

#include "TG/TG.h"

int testek(TG *g, int k) {
    if (g == NULL)
        return 1;
    
    TVIZ *v = g->prim_viz;

    int contador = 0;

    while (v) {
        contador += 1;
        v = v->prox_viz;
    }

    if (contador != k)
        return 0;
    
    return testek(g->prox_no, k);
}
