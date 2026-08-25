#include "TAB/TAB.h"

static int misc1_aux(TAB* a, int nivel)
{
    if (!a)
        return 0;

    int valor;

    if (nivel % 2 != 0)
        valor = a->info;
    else
        valor = -(a->info);

    return valor + misc1_aux(a->esq, nivel + 1) + misc1_aux(a->dir, nivel + 1);
}

int misc1(TAB* a)
{
    return misc1_aux(a, 1);
}

int main(void)
{
    TAB* arvbin = TAB_inicializa();

    arvbin = TAB_cria(10,
        TAB_cria(5,
            TAB_cria(3, TAB_inicializa(), TAB_inicializa()),
            TAB_cria(7, TAB_inicializa(), TAB_inicializa())),
        TAB_cria(20,
            TAB_cria(15, TAB_inicializa(), TAB_inicializa()),
            TAB_cria(25, TAB_inicializa(), TAB_inicializa())));

    printf("A soma é: %d\n", misc1(arvbin));

    TAB_libera(arvbin);
}
