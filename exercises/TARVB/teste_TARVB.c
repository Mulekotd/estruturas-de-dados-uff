#include "TARVB.h"

TARVB *suc_aux(TARVB *a, int x, TARVB *resp) {
  if (!a) return resp;

  int i = 0;
  while ((i < a->nchaves) && (a->chave[i] < x)) i++;
  
  if ((i < a->nchaves) && (a->chave[i] == x)) {
    if ((i + 1) == a->nchaves) return suc_aux(a->filho[i + 1], x, resp);
    else return suc_aux(a->filho[i + 1], x, a);
  } else if (i == a->nchaves) {
    suc_aux(a->filho[i], x, resp);
  } else {
    return suc_aux(a->filho[i], x, a);
  }
}

TARVB *suc(TARVB *a, int x) {
  if (!a) return a;
  return suc_aux(a, x, NULL);
}

int main(int argc, char *argv[]) {
  TARVB *arvore = TARVB_Inicializa();

  int t;

  printf("Digite o grau minimo. Se o valor digitado for menor que 2, t sera considerado igual a 2...\n");
  scanf("%d", &t);

  if (t < 2) t = 2;

  int num = 0, from, to;

  while (num != -1) {
    printf("Digite um numero para adicionar. 0 para imprimir. -9 para remover e -1 para sair\n");
    scanf("%d", &num);
    
    if (num == -9) {
      scanf("%d", &from);
      arvore = TARVB_Retira(arvore, from, t);
      TARVB_Imprime2(arvore);
    } else if (num == -1) {
      printf("\n");
      scanf("%d", &from);

      TARVB *resp = suc(arvore, from);

      if (resp) {
        for (int i = 0; i < resp->nchaves; i++) printf("%d ", resp->chave[i]);
        printf("\n");
      } else {
        printf("NULL\n");
      }

      TARVB_Imprime2(arvore);
      TARVB_Libera(arvore);
      
      return 0;
    } else if (!num) {
      printf("\n");
      TARVB_Imprime2(arvore);
    } else {
      arvore = TARVB_Insere(arvore, num, t);
    }

    printf("\n\n");
  }
}
