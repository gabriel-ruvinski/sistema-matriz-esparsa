#ifndef SPARSE_H
#define SPARSE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    float dado;
    int lin, col;
    struct nodo *prox;
} Matriz_Esparsa;

// ===== FUNÇÕES LISTA =====

Matriz_Esparsa* alocar_nodo(float dado, int lin, int col);
void inserir(Matriz_Esparsa **cabeca, float dado, int lin, int col);
Matriz_Esparsa* buscar(Matriz_Esparsa *cabeca, int lin, int col);
void liberar_lista(Matriz_Esparsa **cabeca);

// ===== FUNÇÕES MATRIZES =====

Matriz_Esparsa* ler_matriz(int linhas, int colunas);
void imprimir_matriz(Matriz_Esparsa *cabeca, int linhas, int colunas);
void imprimir_diagonal(Matriz_Esparsa *cabeca, int linhas, int colunas);
Matriz_Esparsa* somar_matrizes(Matriz_Esparsa *m1, Matriz_Esparsa *m2, int linhas, int colunas);
Matriz_Esparsa* subtrair_matrizes(Matriz_Esparsa *m1, Matriz_Esparsa *m2, int linhas, int colunas);
Matriz_Esparsa* multiplicar_matrizes(Matriz_Esparsa *m1, int lin1, int col1, Matriz_Esparsa *m2, int lin2, int col2);
Matriz_Esparsa* transposta(Matriz_Esparsa *cabeca, int linhas, int colunas);

#endif