#include "TABB/TABB.h"

TABB* maior(TABB *a) {
  if (!a) return NULL;

  while (a->dir)
    a = a->dir;

  return a;
}
