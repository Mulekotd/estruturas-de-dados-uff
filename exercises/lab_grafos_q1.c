#include "TGrafo/TGrafo.h"

static TGrafo *busca_nome(TGrafo *g, const char *nome) {
    while (g && strcmp(g->nome, nome) != 0)
        g = g->prox_no;

    return g;
}

static int segue(TGrafo *pessoa, const char *nome) {
    TVIZ *viz;

    for (viz = pessoa->prim_viz; viz; viz = viz->prox_viz)
        if (strcmp(viz->nome, nome) == 0)
            return 1;

    return 0;
}

// Questão 1 - Quantas pessoas uma determinada pessoa segue?

int numero_seguidos_aux(TVIZ *v) {
    if (!v) return 0;
    return 1 + numero_seguidos_aux(v->prox_viz);
}

int numero_seguidos(TGrafo *g, char *x) {
    TGrafo *aux = busca_nome(g, x);

    if (!g || !aux)
        return 0;

    return numero_seguidos_aux(aux->prim_viz);
};

/* Questão 2 - Quem são os seguidores de uma determinada pessoa?
(função imprime os nomes dos seguidores, caso a flag imprime seja
True, e retorna quantidade de seguidores) */

int seguidores(TGrafo *g, char *nome, int imprime) {
    TGrafo *pessoa;

    int quantidade = 0;

    if (!g || !nome || !busca_nome(g, nome))
        return 0;

    for (pessoa = g; pessoa; pessoa = pessoa->prox_no) {
        if (segue(pessoa, nome)) {
            if (imprime)
                printf("%s\n", pessoa->nome);

            quantidade++;
        }
    }

    return quantidade;
}

// Questão 3 - Quem é a pessoa mais popular? (tem mais seguidores)

TGrafo *mais_popular(TGrafo *g) {
    TGrafo *pessoa;
    TGrafo *popular = NULL;

    int maior_quantidade = -1;

    for (pessoa = g; pessoa; pessoa = pessoa->prox_no) {
        int quantidade = seguidores(g, pessoa->nome, 0);

        if (quantidade > maior_quantidade) {
            maior_quantidade = quantidade;
            popular = pessoa;
        }
    }

    return popular;
}

/* Questão 4 - Quais são as pessoas que só seguem pessoas mais velhas do
que ela própria? (função imprime os nomes das pessoas, caso a
flag imprime seja True, e retorna quantidade de pessoas) */

int segue_mais_velho(TGrafo *g, int imprime) {
    TGrafo *pessoa;

    int quantidade = 0;

    for (pessoa = g; pessoa; pessoa = pessoa->prox_no) {
        TVIZ *viz = pessoa->prim_viz;

        int so_segue_mais_velhos = 1;

        while (viz) {
            TGrafo *seguido = busca_nome(g, viz->nome);

            if (!seguido || seguido->id_no <= pessoa->id_no) {
                so_segue_mais_velhos = 0;
                break;
            }

            viz = viz->prox_viz;
        }

        if (so_segue_mais_velhos) {
            if (imprime)
                printf("%s\n", pessoa->nome);
            quantidade++;
        }
    }

    return quantidade;
}
