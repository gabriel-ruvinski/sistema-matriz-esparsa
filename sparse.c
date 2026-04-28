#include "sparse.h"

// Função para alocar novo nodo
Matriz_Esparsa* alocarNodo() {
    Matriz_Esparsa *novo = (Matriz_Esparsa*)malloc(sizeof(Matriz_Esparsa));
    if (!novo) {
        printf("Erro de alocacao!\n");
        exit(1);
    }
   
    return novo;
}

// Inserir um nó na lista em ordem
void inserir(Matriz_Esparsa **N, float dado, int lin, int col) {
    Matriz_Esparsa *aux;
    Matriz_Esparsa *novo = alocarNodo();

    novo->dado = dado;
    novo->lin = lin;
    novo->col = col;
    novo->prox = NULL;

    // Lista vazia ou novo vem antes do primeiro
    if (*N == NULL || lin < (*N)->lin || (lin == (*N)->lin && col < (*N)->col)) {
        novo->prox = *N;
        *N = novo;
        return;
    }

    // Percorre até achar a posição certa
    aux = *N;
    while (aux->prox != NULL &&
          (aux->prox->lin < lin || (aux->prox->lin == lin && aux->prox->col < col)))
        aux = aux->prox;

    // Insere após aux
    novo->prox = aux->prox;
    aux->prox = novo;
}

// Buscar elemento em determinada posição
Matriz_Esparsa* buscar(Matriz_Esparsa *N, int lin, int col) {
    Matriz_Esparsa *aux = N;

    while (aux != NULL) {
        if (aux->lin == lin && aux->col == col)
            return aux;
        aux = aux->prox;
    }

    return NULL;
}

// Liberar a lista da memória
void liberarLista(Matriz_Esparsa **N) {
    Matriz_Esparsa *aux = *N;

    while (aux != NULL) {
        Matriz_Esparsa *prox = aux->prox;
        free(aux);
        aux = prox;
    }

    *N = NULL;
}

// Lê a matriz do teclado e armazena apenas os diferentes de zero
void lerMatriz(Matriz_Esparsa **N, int linhas, int colunas) {
    float dado;
    int i, j;

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%f", &dado);
            if (dado != 0)
                inserir(N, dado, i, j);
        }
    }
}

void imprimirMatriz(Matriz_Esparsa *N, int linhas, int colunas) {
    int i, j;
    Matriz_Esparsa *aux;

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            aux = buscar(N, i, j);
            if (aux != NULL)
                printf("%.2f ", aux->dado);
            else
                printf("0.00 ");
        }
        printf("\n");
    }
}