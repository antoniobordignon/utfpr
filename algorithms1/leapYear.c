#include <stdio.h>

int main() {
	int year, result;
	scanf("%d", &year);
	result = (year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0);
	result ? printf("Resultado: 1") : printf("Resultado: 0");
}
