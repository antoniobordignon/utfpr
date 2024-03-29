#include <stdio.h>

double* tarefa(double vetor[], int tamanho) {
    // Inicializa um ponteiro para a �ltima posi��o do vetor
    double* resultado = &vetor[tamanho - 1];

    // Procura a �ltima ocorr�ncia de um n�mero negativo no vetor
    for (int i = tamanho - 1; i >= 0; i--) {
        if (vetor[i] < 0) {
            resultado = &vetor[i];
            break;  // Encontrou o n�mero negativo, pode sair do loop
        }
    }

    return resultado;
}

int main() {
    double vet1[5] = {1, 2, 3, 4, 5};
    double *p1 = tarefa(vet1, 5);
    printf("%.2lf\n", *p1);  // Sa�da esperada: 5.00

    double vet2[5] = {-1, 2, 3, 4, 5};
    double *p2 = tarefa(vet2, 5);
    printf("%.2lf\n", *p2);  // Sa�da esperada: -1.00

    return 0;
}

