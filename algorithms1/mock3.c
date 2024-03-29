#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N;
    
    scanf("%d", &N);
    
    int M[N][N], vetor[N];
    int i, j;

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            scanf("%d", &M[i][j]);
        }
    }
   
    for (i=0;i<N;i++){
    	vetor[i] = 0;//zerando todo o vetor
	}

    //realizando somatorio
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            vetor[i] += M[j][i];
        }
    }

    //printf("Matriz:\n");
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    //printf("\n\Somatorios:\n");
    for(i = 0; i < N; i++){
        printf("Soma da coluna %d = %d\n", i, vetor[i]);
    }
   
    int mult=0;
    for(i = 0; i < N; i++){
        mult=vetor[i]*M[i][i];
        printf("Multiplica coluna %d = %d\n", i, mult);
    }
    
    
    return 0;
}
