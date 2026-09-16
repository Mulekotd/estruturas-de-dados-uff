/* 3) Uma função em C que, dada uma árvore binária de busca qualquer, retire todos os elementos
ímpares da árvore original. */

#include "TABB/TABB.h"

TABB* retira_impares(TABB *a) {
  if (!a) return NULL;

  a->esq = retira_impares(a->esq);
  a->dir = retira_impares(a->dir);

  if (a->info % 2 != 0)
    a = TABB_retira(a, a->info);

  return a;
}
