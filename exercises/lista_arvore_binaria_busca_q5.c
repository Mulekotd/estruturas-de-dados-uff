/* 5) Reescreva as operações básicas da ABB para poder armazenar as figuras geométricas
quadrado, triângulo, retângulo e trapézio. A área da figura será usada para definir os elementos
pertencentes a sub-árvore esquerda e a sub-árvore direita. A impressão será em ordem simétrica e,
além da área, devem ser informadas as dimensões da figura. */

#include <stdlib.h>

typedef enum { QUADRADO, TRIANGULO, RETANGULO, TRAPEZIO } TipoFigura;

typedef struct {
  union {
    struct { float lado; } quadrado;
    struct { float base, altura; } triangulo;
    struct { float base, altura; } retangulo;
    struct { float base_maior, base_menor, altura; } trapezio;
  } dim;
  TipoFigura tipo;
} Figura;

float area(Figura f) {
  switch (f.tipo) {
    case QUADRADO:
      return f.dim.quadrado.lado * f.dim.quadrado.lado;
    case TRIANGULO:
      return (f.dim.triangulo.base * f.dim.triangulo.altura) / 2.0;
    case RETANGULO:
      return f.dim.retangulo.base * f.dim.retangulo.altura;
    case TRAPEZIO:
      return ((f.dim.trapezio.base_maior + f.dim.trapezio.base_menor) 
              * f.dim.trapezio.altura) / 2.0;
  }

  return 0;
}

typedef struct arvbinbusca {
  Figura info;
  struct arvbinbusca *esq, *dir;
} TABB;

TABB* TABB_cria(Figura raiz, TABB *esq, TABB *dir) {
  TABB *novo = (TABB *) malloc(sizeof(TABB));
  novo->info = raiz;
  novo->esq = esq;
  novo->dir = dir;
  return novo;
}

TABB* TABB_insere(TABB *a, Figura elem) {
  if (!a) return TABB_cria(elem, NULL, NULL);

  if (area(a->info) > area(elem))
    a->esq = TABB_insere(a->esq, elem);
  else if (area(a->info) < area(elem))
    a->dir = TABB_insere(a->dir, elem);

  return a;
}

TABB* TABB_retira(TABB *a, float area_alvo) {
  if (!a) return a;

  if (area_alvo < area(a->info))
    a->esq = TABB_retira(a->esq, area_alvo);
  else if (area_alvo > area(a->info))
    a->dir = TABB_retira(a->dir, area_alvo);
  else {
    if (!a->esq && !a->dir) {
      free(a);
      a = NULL;
    } else if (!a->esq || !a->dir) {
      TABB *temp = a;
      a = a->esq ? a->esq : a->dir;
      free(temp);
    } else {
      TABB *filho = a->esq;
      while (filho->dir) filho = filho->dir;
      a->info = filho->info;
      a->esq = TABB_retira(a->esq, area(filho->info));
    }
  }

  return a;
}

void imprime_figura(Figura f) {
  printf("area=%.2f | ", area(f));

  switch (f.tipo) {
    case QUADRADO:
      printf("Quadrado (lado=%.2f)\n", f.dim.quadrado.lado);
      break;
    case TRIANGULO:
      printf("Triangulo (base=%.2f, altura=%.2f)\n",
             f.dim.triangulo.base, f.dim.triangulo.altura);
      break;
    case RETANGULO:
      printf("Retangulo (base=%.2f, altura=%.2f)\n",
             f.dim.retangulo.base, f.dim.retangulo.altura);
      break;
    case TRAPEZIO:
      printf("Trapezio (base_maior=%.2f, base_menor=%.2f, altura=%.2f)\n",
             f.dim.trapezio.base_maior, f.dim.trapezio.base_menor,
             f.dim.trapezio.altura);
      break;
  }
}

void TABB_imp_sim(TABB *a) {
  if (a) {
    TABB_imp_sim(a->esq);
    imprime_figura(a->info);
    TABB_imp_sim(a->dir);
  }
}
