#include <stdio.h>
int main (){
	char string[29];
	
	fgets(string, 30, stdin);
	
	int i;
	
	for(i = 0; 28 >= i; i++){
		if(string[i] == 'a' || string[i] == 'A' || string[i] == 'e'|| string[i] =='E' || string[i] == 'i' || string[i] == 'I' || string[i] == 'o' || string[i] == 'O' || string[i] == 'u' || string[i] == 'U' )
			string[i] = '_';
		}
		
	printf("%s", string);
    
}
