#include <stdio.h>

int main () {
    char asnwer;
    scanf("%c", &asnwer);
    if(asnwer == 'A' || asnwer == 'a') {
        printf("Excelente! Parabens!");
    }else if(asnwer == 'B' || asnwer == 'C' || asnwer == 'b' || asnwer == 'c') {
        printf("Voce foi bem.");
    }else if(asnwer == 'D' || asnwer == 'd') {
        printf("Foi por muito pouco!");
    }else if(asnwer == 'F' || asnwer == 'f') {
        printf("Estudar mais na proxima.");
    }else {
       printf("Valor invalido."); 
    } 
}
