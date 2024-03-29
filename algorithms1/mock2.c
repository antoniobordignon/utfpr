#include <stdio.h>
#include <string.h>

int main(){
	char texto[100];
	int totNum = 0, totLetras = 0;
	
	scanf("%[^\n]c", texto);
	
	for(int i = 0; texto[i] != '\0'; i++){
		if(texto[i] >= 48 && texto[i] <= 57){
			texto[i] = '*';
			totNum++;
		}else if (texto[i] >= 97 && texto[i] <= 122){
			texto[i] = '_';	
			totLetras++;
		}else if (texto[i] == 64) {//@
			texto[i] = '\0';
			break;
		}
	}
	
	printf("%s\n", texto);
	printf("Total numericos substituidos: %d\n", totNum);
	printf("Total alfabeticos substituidos: %d", totLetras);
	return 0;
}
