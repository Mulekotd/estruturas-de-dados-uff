#include <stdio.h>
#include <stdlib.h>

typedef struct lseg {
    void* info;
    struct lseg* prox;
} TLSEG;

TLSEG* TLSE_inicializa(void);
TLSEG* TLSE_insere(TLSEG *l, void *elem);

void TLSE_imprime(const TLSEG *l, void (*imprime_elem)(const void *));

TLSEG* TLSE_busca(TLSEG *l, const void *elem, int (*compara)(const void *, const void *));
TLSEG* TLSE_retira(TLSEG *l, const void *elem, int (*compara)(const void *, const void *), void (*libera_elem)(void *));

void TLSE_libera(TLSEG *l, void (*libera_elem)(void *));
