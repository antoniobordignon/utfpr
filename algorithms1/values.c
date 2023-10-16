#include <stdio.h>

int main() {
    int N;

    while (1) {
        scanf("%d", &N);
        
	    if (N > -101 && N < 101) {
	    	if(N == 0){
				printf("NULL \n");	    		
			}else if(N < 0 && N % 2 == 0) {
				printf("EVEN NEGATIVE \n");
			}else if(N > 0 && N % 2 == 0) {
				printf("EVEN POSITIVE \n");
			}else if(N < 0 && N % 2 != 0) {
				printf("ODD NEGATIVE \n");
			}else if(N > 0 && N % 2 != 0) {
				printf("ODD POSITIVE \n");
			}
	    } else if (N == -101){
	        break;
	    } else {
	    	printf("Valor invalido! Tente novamente! \n");
		}
   	}
}
