#include <stdio.h>

int main() {
	int age, result;
	scanf("%d", &age);
	
	result = 18 <= age && age <= 65;
	
	result == 0 ? printf("Resultado: 0") : printf("Resultado: 1");
}
