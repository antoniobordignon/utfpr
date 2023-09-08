#include <stdio.h>

int main() {
	int X, Y, Z, W, result;
	scanf("%d %d %d %d", &X, &Y, &Z, &W);
	
	result = X == Y || Z != W;
	
	result == 1 ? printf("Resultado: Ao menos uma expressão é VERDADEIRA") : printf("Resultado: Todas as expressões são FALSAS");
}
