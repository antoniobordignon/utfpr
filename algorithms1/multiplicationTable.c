#include <stdio.h>

int main() {
    int N;

    while (1) {
        scanf("%d", &N);
        
	    if (N > 2 && N < 1000) {
	    	int i = 1;
	    		
			while (i <= 10) {
		        int result = N * i;
		        printf("%d X %d = %d\n", i, N, result);
		        i++;
	        }
	    	break;
	    } else {
	        printf("Valor invalido! Tente novamente!\n");
	    }
   	}
}
