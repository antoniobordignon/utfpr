#include <stdio.h>

int main() {
	char A, B, C, D, E;
	int sum;
	scanf("%c %c %c %c %c", &A, &B, &C, &D, &E);
	sum = 0;
	if(A == 's') {
		sum += 1;
	}	
	if(B == 's') {
		sum += 1;	
	}
	if(C == 's') {
		sum += 1;	
	}
	if(D == 's') {
		sum += 1;	
	}
	if(E == 's') {
		sum += 1;	
	}
	
	if(sum == 0){
		printf("Inocente");
	}else if(sum <= 2) {
		printf("Suspeito");
	} else if(sum <= 4){
		printf("Cumplice");
	} else {
		printf("Assassino");
	}
}
