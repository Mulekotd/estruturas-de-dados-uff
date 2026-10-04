#include <stdio.h>
#include <stdlib.h>

typedef struct arvb
{
    int nchaves, folha;
    int *chave;
    struct arvb **filho;
} TARVB;

TARVB *TARVB_busca(TARVB *a, int x);
TARVB *TARVB_cria(int t);
void *TARVB_libera(TARVB *a);
