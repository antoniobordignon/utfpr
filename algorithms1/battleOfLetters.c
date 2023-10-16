#include <stdio.h>
#include <string.h>

int main(void) {
    char letters[30];
    int i, consonant, vowel;
	scanf("%s", letters);
    
	consonant = 0; 
	vowel = 0;
    
    for (i = 0; i < strlen(letters); i++) {
        if (letters[i] == '!'){
        	break;	
		} else if (letters[i] == 'a' || letters[i] == 'A' || letters[i] == 'e' || letters[i] == 'E' || letters[i] == 'i' || letters[i] == 'I' || letters[i] == 'o' || letters[i] == 'O' || letters[i] == 'u' || letters[i] == 'U' ) {
            vowel += 1;
        } else {
        	consonant += 1;
		}
    }
    
    if(consonant < vowel) {
	    printf("Ha mais vogais que consoantes.");
	}else if(consonant > vowel) {
		printf("Ha mais consoantes que vogais.");
	} else {
		printf("Empate!");
	}
}
