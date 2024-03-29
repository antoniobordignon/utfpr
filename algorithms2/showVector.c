#include <stdio.h>

int main() {
    int n;

    // Solicita ao usuário o número de elementos no array
    scanf("%d", &n);

    // Declara um array de inteiros e um ponteiro para inteiros
    int numeros[n];

    // Solicita ao usuário que insira os números
    for (int i = 0; i < n; i++) {
        scanf("%d", &numeros[i]);
    }

    // Reinicializa o ponteiro para o início do array
    int *ptr = numeros;
    int i;
    // Imprima os números armazenados no array por meio do ponteiro ptr
    for (i = 0; i < n; i++){
        printf("%d\n", *ptr);
        ptr++;
    }

    return 0;
}