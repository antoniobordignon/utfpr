#include <stdio.h>

int main() {
	double A, B, C;
	scanf("%lf %lf %lf", &A, &B, &C);
	
	int	result = (A + B > C) && (A + C > B) && (B + C > A);
	
	result ? printf("� poss�vel formar um tri�ngulo!") : printf("N�o � poss�vel formar um tri�ngulo!");
}
