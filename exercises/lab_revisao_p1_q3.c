// Faça uma função que verifique se uma TAB segue o padrão AVL.

#include "TAB/TAB.h"

static int maior(int x, int y) {
  if (x >= y)
    return x;

  return y;
}

static int altura_avl(TAB *a, int *eh_avl_flag) {
    if (a == NULL)
        return -1;

    int alt_esq = altura_avl(a->esq, eh_avl_flag);

    if (!(*eh_avl_flag))
        return 0;

    int alt_dir = altura_avl(a->dir, eh_avl_flag);

    if (!(*eh_avl_flag))
        return 0;

    int diferenca = alt_esq - alt_dir;

    if (diferenca < -1 || diferenca > 1)
        *eh_avl_flag = 0; // desbalanceado

    // Altura do nó atual = 1 + maior altura das subárvores
    return 1 + maior(alt_esq, alt_dir);
}

int eh_avl(TAB *a) {
    if (a == NULL)
        return 1;

    int flag = 1;
    altura_avl(a, &flag);

    return flag;
}
