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

Matriz_Esparsa* alocarNodo(); // Alocar novo nó
void inserir(Matriz_Esparsa **N, float dado, int lin, int col); // Inserir um nó na lista em ordem
Matriz_Esparsa* buscar(Matriz_Esparsa *N, int lin, int col); // Buscar elemento em determinada posição
void liberarLista(Matriz_Esparsa **N); // Liberar a lista da memória

// ===== FUNÇÕES MATRIZES =====

void lerMatriz(Matriz_Esparsa **N, int linhas, int colunas); // Lê a matriz do teclado e armazena apenas os diferentes de zero
void imprimirMatriz(Matriz_Esparsa *N, int linhas, int colunas); // Imprime a matriz completa (zeros e não-zeros)
void imprimirDiagonal(Matriz_Esparsa *N, int linhas); // Imprime apenas a diagonal principal
Matriz_Esparsa* somarMatrizes(Matriz_Esparsa *m1, Matriz_Esparsa *m2, int linhas, int colunas); // Soma duas matrizes
Matriz_Esparsa* subtrairMatrizes(Matriz_Esparsa *m1, Matriz_Esparsa *m2, int linhas, int colunas); // Subtrai duas matrizes (m1 - m2)
Matriz_Esparsa* multiplicarMatrizes(Matriz_Esparsa *m1, int lin1, int col1, Matriz_Esparsa *m2, int lin2, int col2); // Multiplica duas matrizes
Matriz_Esparsa* transposta(Matriz_Esparsa *N, int linhas, int colunas); // Gera a matriz transposta

#endif