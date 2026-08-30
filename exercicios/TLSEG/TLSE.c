#include "TLSEG.h"

#include <stdio.h>
#include <stdlib.h>

TLSEG* TLSE_inicializa(void)
{
  return NULL;
}

TLSEG* TLSE_insere(TLSEG *l, void *elem)
{
  TLSEG* novo = malloc(sizeof(TLSEG));

  if (novo == NULL)
  {
    fprintf(stderr, "Erro de alocacao.\n");
    return l;
  }

  novo->info = elem;
  novo->prox = l;

  return novo;
}

void TLSE_imprime(const TLSEG *l, void (*imprime_elem)(const void *))
{
  while (l != NULL)
  {
    imprime_elem(l->info);
    l = l->prox;
  }

  printf("\n");
}

TLSEG* TLSE_busca(
    TLSEG *l,
    const void *elem,
    int (*compara)(const void *, const void *))
{
  while (l != NULL)
  {
    if (compara(l->info, elem) == 0)
      return l;

    l = l->prox;
  }

  return NULL;
}

TLSEG* TLSE_retira(
    TLSEG *l,
    const void *elem,
    int (*compara)(const void *, const void *),
    void (*libera_elem)(void *))
{
  TLSEG* anterior = NULL;
  TLSEG* atual = l;

  while (atual != NULL)
  {
    if (compara(atual->info, elem) == 0)
    {
      if (anterior == NULL)
        l = atual->prox;
      else
        anterior->prox = atual->prox;

      if (libera_elem != NULL)
        libera_elem(atual->info);

      free(atual);

      return l;
    }

    anterior = atual;
    atual = atual->prox;
  }

  return l;
}

void TLSE_libera(TLSEG *l, void (*libera_elem)(void *))
{
  TLSEG *proximo;

  while (l != NULL)
  {
    proximo = l->prox;

    if (libera_elem != NULL)
      libera_elem(l->info);

    free(l);

    l = proximo;
  }
}
