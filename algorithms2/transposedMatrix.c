#include <stdio.h>
int main() {
    int matrix[3][3];
    int matrix2[3][3];
    int i;
    int j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    i = 0;
    j = 0;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matrix2[i][j] = matrix[j][i];
        }
    }

    i = 0;
    j = 0;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }
}