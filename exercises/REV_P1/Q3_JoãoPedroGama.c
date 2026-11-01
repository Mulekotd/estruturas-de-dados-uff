#include <string.h>

#include "../TAB/TAB.h"

int abEabb_aux(TAB *a, TAB **anterior) {
  // Caso base: árvore vazia é ABB
  if (a == NULL) return 1;

  // Percorre primeiro a subárvore esquerda (percurso em ordem)
  if (!abEabb_aux(a->esq, anterior))
    return 0;

  // O nó atual deve ser maior que o anterior
  if (*anterior != NULL && a->info <= (*anterior)->info)
    return 0;

  *anterior = a;

  // Continua o percurso em ordem pela subárvore direita
  return abEabb_aux(a->dir, anterior);
}

int abeABB(TAB *a) {
  TAB *anterior = NULL;
  return abEabb_aux(a, &anterior);
}

int main(void) {
  int no, pai;

  printf("Digite a raiz da arvore... ");
  scanf("%d", &no);

  TAB *a = TAB_cria(no, NULL, NULL), *resp;

  char repete;

  do {
    char lado[2];

    printf("Quer continuar inserindo nos na árvore (digite N ou n para parar)? ");
    scanf(" %c", &repete);

    if ((repete == 'N') || (repete == 'n')) break;

    printf("Digite o pai (que deve existir), o filho a ser inserido e a posição E(ESQ) ou D(DIR)... ");
    scanf("%d%d%s", &pai, &no, lado);

    resp = TAB_busca(a, pai);

    if (!resp) {
      TAB_libera(a);
      return 0;
    }

    if (strcmp(lado, "E") == 0)
      resp->esq = TAB_cria(no, NULL, NULL);
    else
      resp->dir = TAB_cria(no, NULL, NULL);
  } while (1);

  TAB_imp_ident(a);

  printf("\n");
  printf("Arvore binaria e binaria de busca? %d\n", abeABB(a));

  TAB_libera(a);

  return 0;
}
