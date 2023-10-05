#include <stdio.h>

int main() {
	int month, quarter;
	scanf("%d", &month);
	if(month >= 1 && month <= 3){
		quarter = 1;
	}else if(month >= 4 && month <= 6){
		quarter = 2;
	}else if(month >= 7 && month <= 9){
		quarter = 3;
	}else if(month >= 10 && month <= 12){
		quarter = 4;
	};
	switch(quarter) {
		case 1:
			printf("Primeiro trimestre");
			break;
		case 2:
			printf("Segundo trimestre");
			break;
		case 3:
			printf("Terceiro trimestre");
			break;
		case 4:
			printf("Quarto trimestre");
			break;
		default:
			printf("Mes invalido");
	}
}
