#include <stdio.h>
#include <stdlib.h>

void imprime_int(const void *info)
{
    const int *numero = info;

    printf("%d ", *numero);
}

int compara_int(const void *primeiro, const void *segundo)
{
    const int* a = primeiro;
    const int* b = segundo;

    return (*a > *b) - (*a < *b);
}

int* cria_int(int valor)
{
    int* numero = malloc(sizeof(int));

    if (numero != NULL)
        *numero = valor;

    return numero;
}
