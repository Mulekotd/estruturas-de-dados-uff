#include "TLSE/TLSE.h"

int Contrario(TLSE *l1, TLSE *l2)
{
    TLSE *p1 = l1;
    TLSE *p2 = l2;

    int tamanho1 = 0;
    int tamanho2 = 0;
    int i;

    int* valores;

    while (p1 != NULL)
    {
        tamanho1++;
        p1 = p1->prox;
    }

    while (p2 != NULL)
    {
        tamanho2++;
        p2 = p2->prox;
    }

    if (tamanho1 != tamanho2)
        return 0;

    valores = (int *) malloc(tamanho1 * sizeof(int));
    p1 = l1;

    for (i = 0; i < tamanho1; i++)
    {
        valores[i] = p1->info;
        p1 = p1->prox;
    }

    p2 = l2;

    for (i = tamanho1 - 1; i >= 0; i--)
    {
        if (valores[i] != p2->info)
        {
            free(valores);
            return 0;
        }

        p2 = p2->prox;
    }

    free(valores);

    return 1;
}
