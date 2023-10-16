#include <stdio.h>

int main() {
	double value;
	scanf("%lf", &value);
	
	if((value >= 0) && (value <= 25)){
		printf("Intervalo [0,25]");
	}else if((value >= 25) && (value <= 50)){
		printf("Intervalo (25,50]");
	}else if((value >= 50) && (value <= 75)){
		printf("Intervalo (50,75]");
	}else if((value >= 75) && (value <= 100)){
		printf("Intervalo (75,100]");
	}else{
		printf("Fora de intervalo");
	}
}
