#include <stdio.h>
#include <stdlib.h>

typedef struct ab
{
    int info;
    int cor; // 1 - vermelho, 0 - preto
    struct ab *esq, *dir;
} TAB;

#define PRETO 0
#define VERMELHO 1

static void colore_aux(TAB *arv, int nivel)
{
    if (!arv)
        return;

    if (nivel % 2 == 0)
        arv->cor = PRETO;
    else
        arv->cor = VERMELHO;

    colore_aux(arv->esq, nivel + 1);
    colore_aux(arv->dir, nivel + 1);
}

void colore(TAB *arv)
{
    colore_aux(arv, 0);
}
