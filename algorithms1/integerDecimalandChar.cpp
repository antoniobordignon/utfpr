#include <stdio.h>

int main(){
	int integer;
	float real;
	char text;
	
	scanf("%d %f %c", &integer, &real, &text);
		
	printf("%d %.4f %c", integer, real, text);
}
