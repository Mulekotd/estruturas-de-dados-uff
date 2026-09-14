#include "TABB/TABB.h"

TABB* menor(TABB *a) {
  if (!a) return NULL;

  while (a->esq)
    a = a->esq;

  return a;
}
