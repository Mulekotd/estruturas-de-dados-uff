// Descubra a quantidade de nós de um grafo.

#include "TG/TG.h"

int nn(TG *g) {
    if (g == NULL)
        return 0;

    return 1 + nn(g->prox_no);
}
