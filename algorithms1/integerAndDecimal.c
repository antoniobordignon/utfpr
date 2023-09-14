#include <stdio.h>

int main(){
	float real;
	int zero;
	scanf("%f", &real);
	
	zero = real;
		
	printf("%i %.5f", zero, real - zero);
}
