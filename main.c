#include "sparse.h"

int main() {
    Matriz_Esparsa *m1 = NULL;
    int linhas, colunas;

    printf("=== TESTE MATRIZ ESPARSA ===\n\n");

    printf("Digite o numero de linhas: ");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas: ");
    scanf("%d", &colunas);

    printf("\nDigite os valores da matriz:\n");
    lerMatriz(&m1, linhas, colunas);

    printf("\nMatriz impressa:\n");
    imprimirMatriz(m1, linhas, colunas);

    printf("\nDiagonal principal:\n");
    imprimirDiagonal(m1, linhas);

    liberarLista(&m1);

    return 0;
}