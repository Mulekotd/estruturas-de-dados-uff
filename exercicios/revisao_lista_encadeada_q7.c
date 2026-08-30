#include "TLSE/TLSE.h"

void i_p(TLSE *l)
{
    TLSE* p;

    int tamanho = 0;
    int* valores;

    int i;

    int posicao = 0;

    for (p = l; p != NULL; p = p->prox)
        tamanho++;

    valores = (int *) malloc(tamanho * sizeof(int));
    for (p = l; p != NULL; p = p->prox)
        valores[posicao++] = p->info;

    for (i = 0; i < tamanho; i++)
    {
        if (valores[i] % 2 != 0)
        {
            l->info = valores[i];
            l = l->prox;
        }
    }

    for (i = 0; i < tamanho; i++)
    {
        if (valores[i] % 2 == 0)
        {
            l->info = valores[i];
            l = l->prox;
        }
    }

    free(valores);
}
