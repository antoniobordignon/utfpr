#include <stdio.h>
#include <string.h>

char * acharVogal(char v, char *vetor){
	int i;
	for (i=0; i<strlen(vetor); i++){
		if (v == vetor[i])
			return &vetor[i];
	}
	return NULL;
}

int main(){	
	char frase[50];
	char vogal;
	
	scanf("%[^\n]s", frase);
	scanf(" %c", &vogal);
	
	// adicione sua resposta abaixo deste comentário.
	
	char *retorno;
	
	retorno = acharVogal(vogal, frase);
	
	if(retorno == 0){
	    printf("Vogal nao encontrada.");
	} else {
        printf("Encontrou a vogal: %c", retorno[0]);
	}
    	
	return 0;
}