#include <stdio.h>

int main() {
	int A, B;
	float result;
	
	scanf("%d %d", &A, &B);
	
	result = (float) A / B;
	printf("divisao de %d por %d da %.2f", A, B, result);
}
