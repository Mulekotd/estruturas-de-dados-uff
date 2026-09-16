#include <stdio.h>
#include <stdlib.h>

typedef struct avl {
  int info, alt;
  struct avl *esq, *dir;
} TAVL;

void TAVL_libera(TAVL *t);
TAVL* TAVL_busca(int e, TAVL *t);
static int calc_alt(TAVL *t);
static int max(int l, int r);
static TAVL* TAVL_rot_dir(TAVL *t);
static TAVL* TAVL_rot_esq(TAVL *t);
static TAVL* TAVL_rot_esq_dir(TAVL *t);
static TAVL* TAVL_rot_dir_esq(TAVL *t);
TAVL* TAVL_insere(int e, TAVL *t);
TAVL* TAVL_retira(int x, TAVL *t);
int calc_alt_retira(TAVL *t);
int FB(TAVL *t);
void imprime_aux(TAVL *a, int andar);
void TAVL_imprime(TAVL *a);
