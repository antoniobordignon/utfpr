#include <stdio.h>

int main() {
	double A, B, C;
	scanf("%lf %lf %lf", &A, &B, &C);
	
	int	result = (A + B > C) && (A + C > B) && (B + C > A);
	
	result ? printf("É possível formar um triângulo!") : printf("Não é possível formar um triângulo!");
}
