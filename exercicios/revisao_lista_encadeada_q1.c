#include "TLSE/TLSE.h"

void inverte(TLSE *l)
{
    if (!l || !l->prox)
        return;

    TLSE* ultimo = l;

    while (ultimo->prox)
        ultimo = ultimo->prox;

    int tmp = l->info;
    l->info = ultimo->info;
    ultimo->info = tmp;

    TLSE* penultimo = l;

    while (penultimo->prox != ultimo)
        penultimo = penultimo->prox;

    penultimo->prox = NULL;

    inverte(l->prox);

    penultimo->prox = ultimo;
}
