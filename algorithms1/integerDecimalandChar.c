#include <stdio.h>

int main() {
	int X, Y, Z, W, result;
	scanf("%d %d %d %d", &X, &Y, &Z, &W);
	
	result = X == Y || Z != W;
	
	result == 1 ? printf("Resultado: Ao menos uma express�o � VERDADEIRA") : printf("Resultado: Todas as express�es s�o FALSAS");
}
