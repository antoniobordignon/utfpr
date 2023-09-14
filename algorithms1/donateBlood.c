#include <stdio.h>

int main() {
	char gender;
	int age, weight, times;
	
	scanf("%d %d %c %d", &age, &weight, &gender, &times);
	
	if((age >= 18 && age <= 72) && (((gender == 'm') && (times < 4)) || ((gender == 'f') && (times < 5))) && (weight >= 42)){
		printf("Pode ser doador");
	} else if((gender != 'm') && (gender != 'f')) {
		printf("Genero invalido");
	} else {
		printf("Nao pode ser doador");
	}
}
