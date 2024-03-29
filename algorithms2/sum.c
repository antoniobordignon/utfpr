#include <stdio.h>

int main(){
	int i,N = 0;
	scanf("%d", &N);
	
	int V[N];
	
	for(i=0; i<N; i++){
		scanf("%d", &V[i]);
	}
	int t = 0;	
	for(i=0; i<N; i++){
		if(i % 2 == 0){
			printf("Y[%d] = %d \n", t, V[i]);
			t++;
		}
	}	
}
