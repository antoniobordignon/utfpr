#include <stdio.h>

void printMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int processaMatriz(int linhas, int colunas, int X, int matriz[linhas][colunas]) {
    int alteracoes = 0;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] > X) {
                matriz[i][j] = 0;
                alteracoes++;
            }
        }
    }
    return alteracoes;
}