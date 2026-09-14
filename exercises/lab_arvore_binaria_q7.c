#include "TAB/TAB.h"

// Lê um número a partir de str[*i], avançando *i
// até o próximo delimitador (' ', '<' ou '>').
int pegaInfo(char *str, int *i) {
    char buffer[32];
    int j = 0;

    while (str[*i] != ' ' && str[*i] != '<' && str[*i] != '>') {
        buffer[j++] = str[*i];
        (*i)++;
    }

    buffer[j] = '\0';

    return atoi(buffer);
}

// Faz o parsing recursivo a partir da posição *i,
// deixando *i posicionado logo após o '>' que fecha este nó.
TAB *str2ab_aux(char *str, int *i) {
    while (str[*i] == ' ') (*i)++;   // pula espaços

    if (str[*i] != '<') return NULL; // formato inesperado
    (*i)++;                          // consome '<'

    while (str[*i] == ' ') (*i)++;

    // Subárvore vazia: "<>"
    if (str[*i] == '>') {
        (*i)++;                      // consome '>'
        return NULL;
    }

    // Lê a informação da raiz
    int info = pegaInfo(str, i);

    while (str[*i] == ' ') (*i)++;

    // Recursão: subárvore esquerda, depois direita
    TAB *esq = str2ab_aux(str, i);

    while (str[*i] == ' ') (*i)++;

    TAB *dir = str2ab_aux(str, i);

    while (str[*i] == ' ') (*i)++;

    if (str[*i] == '>') (*i)++;      // consome '>' de fechamento

    return TAB_cria(info, esq, dir);
}

TAB *str2ab(char *str) {
    if (!str) return NULL;

    int i = 0;
    return str2ab_aux(str, &i);
}
