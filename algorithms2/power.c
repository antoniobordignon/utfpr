#include <stdio.h>
#include <math.h>

int main(){
	int n = 0, i, c, j, sum = 0;

	scanf("%d", &n);
	
	int v[n], w[n];
	
	for(i = 0; i<n; i++){
		scanf("%d", &v[i]);
	}
	
	for(c = 0; c<n; c++){
		scanf("%d", &w[c]);
	}
	for(j = 0; j<n; j++){
		sum += pow(v[j], w[j]);
	}
	printf("%d", sum);
}
