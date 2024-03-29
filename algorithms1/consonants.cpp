#include <stdio.h>
#include <string.h>

int main () {
	char letters[100];
    int i, consonant, vowel;
	scanf("%[^\n]", letters);
    
	consonant = 0; 
	vowel = 0;
    
    for (i = 0; i < strlen(letters); i++) {
        if(letters[i] == '!'){
		    break;
		}else if (letters[i] == ' '|| letters[i] == 'a' || letters[i] == 'A' || letters[i] == 'e' || letters[i] == 'E' || letters[i] == 'i' || letters[i] == 'I' || letters[i] == 'o' || letters[i] == 'O' || letters[i] == 'u' || letters[i] == 'U' ) {
            vowel += 1;
        } else {
        	consonant += 1;
		}
    }
    
    printf("Consoantes: %d, total de letras: %d", consonant, consonant + vowel);
}
