/* 2) Dados um grafo e dois nós (x e y), retorne um caminho arbitrário entre x e y.
Se não houver caminho, o retorno é NULL. */

#include "TG/TG.h"
#include "TLSE/TLSE.h"

// Função auxiliar recursiva de DFS.
TLSE* caminho_aux(TG *g, int atual, int y, TLSE **visitados) {
  *visitados = TLSE_insere(*visitados, atual);

  // Caso base: achou o destino
  if (atual == y)
    return TLSE_insere(NULL, atual);

  TG *no = TG_busca_no(g, atual);
  
  if (!no) return NULL;

  TVIZ *v = no->prim_viz;

  while (v) {
    if (!TLSE_busca(*visitados, v->id_viz)) {
      TLSE *resto = caminho_aux(g, v->id_viz, y, visitados);

      if (resto) {
        // Achou caminho por este vizinho: monta atual + resto
        return TLSE_insere(resto, atual);
      }
    }

    v = v->prox_viz;
  }

  return NULL;
}

TLSE* caminho(TG *g, int x, int y) {
  if (!TG_busca_no(g, x) || !TG_busca_no(g, y))
    return NULL;

  TLSE *visitados = NULL;
  TLSE *resultado = caminho_aux(g, x, y, &visitados);

  TLSE_libera(visitados);

  return resultado;
}
