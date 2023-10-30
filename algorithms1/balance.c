#include <stdio.h>

int main() {
	float payable, receivable, newValue;
	int entries, i;
	scanf("%d", &entries);
	
	for(i = 0; i < entries; i++){
		scanf("%f", &newValue);
		if(newValue > 0){
			receivable += newValue;
		} else if(newValue < 0){
			payable += newValue;
		}
	}
	
	printf("Pagar: R$ %.2f\nReceber: R$ %.2f\nSaldo: R$ %.2f", payable, receivable, receivable + payable);
	
}


