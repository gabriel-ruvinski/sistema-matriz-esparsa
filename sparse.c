#include "sparse.h"

// Função para alocar novo nodo
Matriz_Esparsa* alocarNodo(float dado, int lin, int col) {
    Matriz_Esparsa *novo = (Matriz_Esparsa*)malloc(sizeof(Matriz_Esparsa));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria\n");
        exit(1);
    }
    novo->dado = dado;
    novo->lin = lin;
    novo->col = col;
    novo->prox = NULL;
    return novo;
}