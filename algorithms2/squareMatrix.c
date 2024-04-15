#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** aloca_matriz_quadrada(int n) {
    int** mat;
    int i;

    mat = (int**)malloc(n * sizeof(int*));
    if (mat == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++) {
        mat[i] = (int*)malloc(n * sizeof(int));
        if (mat[i] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
    }

    return mat;
}

void libera_matriz(int** mat, int n) {
    if (mat == NULL)
        return;

    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);
}