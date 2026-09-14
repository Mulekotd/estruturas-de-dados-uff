#include "TGrafo.h"

TGrafo* TGrafo_inicializa() {
  return NULL;
}

void TGrafo_imprime(TGrafo *g) {
  while (g) {
    printf("Vizinhos do No %s:\n", g->nome);
    TVIZ *v = g->prim_viz;
    
    while (v) {
      printf("%s ", v->nome);
      v = v->prox_viz;
    }

    printf("\n");
    g = g->prox_no;
  }
}

void TGrafo_imp_rec(TGrafo *g) {
  if (g) {
    printf("%s:\n", g->nome);
    TVIZ *v = g->prim_viz;

    while (v) {
      printf("%s ", v->nome);
      v = v->prox_viz;
    }

    TGrafo_imp_rec(g->prox_no);
  }
}

void TGrafo_libera_viz(TVIZ *v) {
  while (v) {
    TVIZ *temp = v;
    v = v->prox_viz;
    free(temp);
  }
}

void TGrafo_libera_viz_rec(TVIZ *v) {
  if (!v) return;
  TGrafo_libera_viz_rec(v->prox_viz);
  free(v);
}

void TGrafo_libera(TGrafo *g) {
  while (g) {
    TGrafo_libera_viz(g->prim_viz);
    TGrafo *temp = g;
    g = g->prox_no;
    free(temp);
  }
}

void TGrafo_libera_rec(TGrafo *g) {
  if (g) {
    TGrafo_libera_viz(g->prim_viz);
    TGrafo_libera_rec(g->prox_no);
    free(g);
  }
}

TGrafo* TGrafo_busca_no(TGrafo* g, int x) {
  if (!g || (g->id_no != x))
    return g;

  return TGrafo_busca_no(g->prox_no, x);
}

TVIZ* TGrafo_busca_aresta(TGrafo *g, int no1, int no2) {
  TGrafo *p1 = TGrafo_busca_no(g, no1), *p2 = TGrafo_busca_no(g, no2);

  if ((!p1) || (!p2))
    return NULL;

  TVIZ *resp = p1->prim_viz;

  while (resp && (resp->id_viz != no2))
    resp = resp->prox_viz;

  return resp;
}

TGrafo* TGrafo_ins_no(TGrafo *g, int x, char* nome) {
  TGrafo *p = TGrafo_busca_no(g, nome);

  if (!p) {
    p = (TGrafo *) malloc(sizeof(TGrafo));
    p->id_no = x;
    p->nome = nome;
    p->prox_no = g;
    p->prim_viz = NULL;
    g = p;
  }

  return g;
}

void TGrafo_ins_um_sentido(TGrafo *g, int id_no1, char *nome_no1, int id_no2, char *nome_no2) {
  TGrafo *p = TGrafo_busca_no(g, id_no1);
  TVIZ *nova = (TVIZ *) malloc(sizeof(TVIZ));
  nova->id_viz = id_no2;
  nova->nome = nome_no2;
  nova->prox_viz = p->prim_viz;
  p->prim_viz = nova;
}

void TGrafo_ins_aresta(TGrafo *g, int id_no1, char* nome_no1, int id_no2, char* nome_no2) {
  TVIZ *v = TGrafo_busca_aresta(g, id_no1, id_no2);

  if (v) return;

  TGrafo_ins_um_sentido(g, id_no1, nome_no1, id_no2, nome_no2);
  TGrafo_ins_um_sentido(g, id_no2, nome_no2, id_no1, nome_no1);
}

void TGrafo_retira_um_sentido(TGrafo *g, int no1, int no2) {
  TGrafo *p = TGrafo_busca_no(g, no1);

  if (!p) return;

  TVIZ *ant = NULL, *atual = p->prim_viz;

  while (atual && (atual->id_viz != no2)) {
    ant = atual;
    atual = atual->prox_viz;
  }

  if (!ant)
    p->prim_viz = atual->prox_viz;
  else
    ant->prox_viz = atual->prox_viz;

  free(atual);
}

void TGrafo_retira_aresta(TGrafo *g, int no1, int no2) {
  TVIZ* v = TGrafo_busca_aresta(g, no1, no2);

  if (!v) return;

  TGrafo_retira_um_sentido(g, no1, no2);
  TGrafo_retira_um_sentido(g, no2, no1);
}

TGrafo* TGrafo_retira_no(TGrafo *g, int no) {
  TGrafo *p = g, *ant = NULL;

  while (p && (p->id_no != no)) {
    ant = p;
    p = p->prox_no;
  }

  if (!p)
    return g;
  
  while (p->prim_viz) TGrafo_retira_aresta(g, no, p->prim_viz->id_viz);
  
  if (!ant)
    g = g->prox_no;
  else
    ant->prox_no = p->prox_no;
  
  free(p);
  
  return g;
}
