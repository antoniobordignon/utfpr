#include <stdio.h>

int main() {
	int A, B, C, D, result;
	scanf("%d %d %d %d", &A, &B, &C, &D);
	result = A > B && C < D;
	printf("Resultado: %d", result);
}
