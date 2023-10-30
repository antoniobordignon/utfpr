#include <stdio.h>

int main() {
    int N, i;
    scanf("%d", &N);
    
    while (N <= 5 || N >= 200 ){
    	printf("Valor invalido! Tente novamente!\n");
    	scanf("%d", &N);
 	}
 	if(N%2 == 0 ) {
 		for(i = 2; i <= N; i+=2){
    	printf("%d^2 = %d\n", i, i * i);	
    	}
	} else {
		for(i = 2; i <= N-1; i+=2) {
	 	  	printf("%d^2 = %d\n", i, i * i);
		}
	}
}
