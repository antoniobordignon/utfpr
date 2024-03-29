#include<stdio.h>

int main(){
	int N, i;
	
	scanf("%d", &N);
	
	float X[N];
	
	for(i = 0; i<N; i++){
		scanf("%f", &X[i]);
	}
	
	float value;
	scanf("%f", &value);
	
	int position=-1;
	for(i = 0; i<N; i++){
		if(X[i] == value){
			position = i;
			break;
		}
	}
	
	if(position > -1){
		printf("Encontrado na posicao %d", position);
	}else {
		printf("Valor nao esta armazenado no vetor");
	}
	return 0;
}
