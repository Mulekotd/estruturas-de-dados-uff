#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct viz {
	int id_viz;
	char *nome;
	struct viz *prox_viz;
} TVIZ;

typedef struct grafo {
	int id_no;
	char *nome;
	TVIZ *prim_viz;
	struct grafo *prox_no;
} TGrafo;

TGrafo* TGrafo_inicializa();
void TGrafo_imprime(TGrafo *g);
void TGrafo_libera(TGrafo *g);
TGrafo* TGrafo_busca_no(TGrafo* g, int x);
TVIZ* TGrafo_busca_aresta(TGrafo *g, int no1, int no2);
TGrafo* TGrafo_ins_no(TGrafo *g, int x, char *nome);
void TGrafo_ins_aresta(TGrafo *g, int id_no1, char* nome_no1, int id_no2, char* nome_no2);
void TGrafo_retira_aresta(TGrafo *g, int no1, int no2);
TGrafo* TGrafo_retira_no(TGrafo *g, int no);
