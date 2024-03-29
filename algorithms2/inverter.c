#include <stdio.h>

void inverter(int vet[], int lenght) {
    int vectorCopy[lenght]; 
    int i, j;
    
    for (i = 0; i < lenght; i++) {
        vectorCopy[i] = vet[i];
    }
    
    j = lenght-1;
    for (i = 0; i < lenght; i++) {
        vet[i] = vectorCopy[j];
        j--;
    }
}

void printVetor(int vet[], int lenght)
{
    int i;
    for (i = 0; i < lenght; i++)
    {
        printf("%d ", vet[i]);
    }
}
