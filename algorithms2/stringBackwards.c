#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    // Solicita ao usuário que insira uma string
    fgets(str, sizeof(str), stdin);

    // Remove o caractere de nova linha do final da string
    str[strcspn(str, "\n")] = '\0';

    // Declara um ponteiro de caractere para a string
    char *ptr = str;

    // Encontra o final da string usando o ponteiro
    while(*ptr != '\0')
        ptr++;
        

    // Imprime a string invertida usando o ponteiro
    ptr--;
    while(ptr >= str){
        printf("%c", *ptr);
        ptr--;
    }
    
    return 0;
}