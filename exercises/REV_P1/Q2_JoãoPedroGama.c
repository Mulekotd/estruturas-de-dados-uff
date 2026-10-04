#include "../TG/TG.h"
#include "../TLSE/TLSE.h"

void contaCC_aux(TG *g, TG *cabeca, TLSE **visitados) {
    if (g == NULL)
      return;

    // Começo adicionando g->id_no à lista de visitados
    *visitados = TLSE_insere(*visitados, g->id_no);

    TVIZ *v = g->prim_viz;

    while (v) {
        // Se o vizinho ainda não foi visitado
        if (!TLSE_busca(*visitados, v->id_viz)) {
            TG *vizinho = TG_busca_no(cabeca, v->id_viz); // Busco o nó com id->no == id->viz
            contaCC_aux(vizinho, cabeca, visitados); // Caminho nos vizinhos desse nó
        }

        v = v->prox_viz;
    }
}

int contaCC(TG *g) {
    int contagem = 0;

    TLSE *visitados = TLSE_inicializa();

    TG *atual = g;

    while (atual) {
        // Caso o grafo ainda não foi visitado
        if (!TLSE_busca(visitados, atual->id_no)) {
            contagem++; // Adiciona 1 à contagem de componentes conexas
            contaCC_aux(atual, g, &visitados); // Apenas caminha nos vizinhos do nó desse grafo
        }

        atual = atual->prox_no;
    }

    TLSE_libera(visitados);

    return contagem;
}

int main(void){
  TG *g = TG_inicializa();
  int n;

  do{
    scanf("%d", &n);
    if(n <= 0) break;
    g = TG_ins_no(g, n);
  } while(1);
  
  int m;

  do{
    scanf("%d%d", &n, &m);
    if((n <= 0) || (m <= 0)) break;
    TG_ins_aresta(g, n, m);
  } while(1);

  TG_imprime(g);
  printf("Numero de componentes conexos? %d\n", contaCC(g));
  TG_libera(g);

  return 0;
}
