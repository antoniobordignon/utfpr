#include <stdio.h>

int main() {
	int n, i, j;
	
	scanf("%d", &n);
	
	float V[n];
	
	for(i = 0; i <= n; i++){
		scanf("%f", &V[i]);
	}
	
	for(j = 0; j < n; j++){
		printf("V[%d] = %.1f\n", j, V[j]);
	}
	
	for(j = n-1; j > -1 ; j--){
		printf("V[%d] = %.1f\n", j, V[j]);
	}
}
