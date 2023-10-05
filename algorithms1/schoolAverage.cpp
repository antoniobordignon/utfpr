#include <stdio.h>

int main() {
	double a, b, c, avarage;
	scanf("%lf %lf %lf", &a, &b, &c);
	avarage = (a + b + c) / 3;
	
	printf("Media: %0.2lf\n", avarage);
	
	if(avarage >= 7){
		printf("Situacao: Aprovado");
	}else if((avarage < 7) && (avarage >= 5)){
		printf("Situacao: Recuperacao");
	}else if(avarage < 5){
		printf("Situacao: Reprovado");
	}
}
