/* 4) Uma função em C que, dada uma árvore binária de busca qualquer, retorne, num vetor, todos
os elementos menores que N. */

#include <limits.h>
#include "TABB/TABB.h"

void mN_aux(TABB *a, int N, int *vet, int *i) {
  if (!a) return;

  if (a->info >= N) {
    mN_aux(a->esq, N, vet, i);
  } else {
    mN_aux(a->esq, N, vet, i);
    vet[*i] = a->info;
    (*i)++;
    mN_aux(a->dir, N, vet, i);
  }
}

int* mN(TABB *a, int N) {
  if (!a) return NULL;

  int max = TABB_conta_nos(a);
  int *vet = (int *) malloc((max + 1) * sizeof(int));
  int i = 0;

  mN_aux(a, N, vet, &i);
  vet[i] = INT_MIN;

  return vet;
}
