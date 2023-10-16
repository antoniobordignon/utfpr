#include <stdio.h>
#include <string.h>

int main() {
	char words[100];
	int a, e, i, o, u, j;
	
	scanf("%[^\n]", words);
	a = 0;
	e = 0;
	i = 0;
	o = 0;
	u = 0;	
	for(j = 0; j < strlen(words); j++){
		if(words[j] == 'a' || words[j] == 'A') {
			a += 1;
		}else if(words[j] == 'e' || words[j] == 'E') {
			e += 1;
		}else if(words[j] == 'i' || words[j] == 'I') {
			i += 1;
		}else if(words[j] == 'o' || words[j] == 'O') {
			o += 1;
		}else if(words[j] == 'u' || words[j] == 'U') {
			u += 1;
		}else if(words[j] == 'x' || words[j] == 'X') {
			j += 1;
			break;
		}
	}
	
	printf("a: %d, e: %d, i: %d, o: %d, u: %d, total de letras: %d", a, e, i, o, u, j);
}
