#include "TLSEG.h"
#include "generics/Inteiro.h"

int main(void)
{
    TLSEG* l = TLSE_inicializa();

    int* n1 = cria_int(10);
    int* n2 = cria_int(20);
    int* n3 = cria_int(30);

    if (n1 == NULL || n2 == NULL || n3 == NULL)
    {
        free(n1);
        free(n2);
        free(n3);

        fprintf(stderr, "Erro de alocacao.\n");
        return 1;
    }

    l = TLSE_insere(l, n1);
    l = TLSE_insere(l, n2);
    l = TLSE_insere(l, n3);

    TLSE_imprime(l, imprime_int);

    int procurado = 20;

    TLSEG* encontrado = TLSE_busca(
        l,
        &procurado,
        compara_int);

    if (encontrado != NULL)
        printf("Elemento encontrado: %d\n",
               *(int *)encontrado->info);
    else
        printf("Elemento nao encontrado.\n");

    l = TLSE_retira(
        l,
        &procurado,
        compara_int,
        free);

    TLSE_imprime(l, imprime_int);

    TLSE_libera(l, free);

    return 0;
}
