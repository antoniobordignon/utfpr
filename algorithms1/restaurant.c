#include <stdio.h>

int main () {
    int firstValue;
    float secondValue, total;
    scanf("%d %f", &firstValue, &secondValue);
    
    if(firstValue == 1) {
        total = secondValue * 4.00;
    }else if(firstValue == 2) {
        total = secondValue * 4.50;
    }else if(firstValue == 3) {
        total = secondValue * 5.00;
    }else if(firstValue == 4) {
        total = secondValue * 2.00;
    }else if(firstValue == 5) {
        total = secondValue * 1.50;
    }
    total > 0 ? printf("Total: R$ %.2f", total) : printf("Codigo invalido");
}
