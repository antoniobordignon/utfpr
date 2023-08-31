#include <stdio.h>

int main(){
	int kwh;
	double tarifa, taxas, servicos, valorconsumo, total;
	
	scanf("%d %lf %lf %lf", &kwh, &tarifa, &taxas, &servicos);
	
	valorconsumo = kwh * tarifa;
	
	total = valorconsumo + taxas + servicos;
	
	
	printf("Dados do faturamento:\n");
	printf("Consumo............:%d kWh\n", kwh);
	printf("Tarifa (R$)........:%.3lf\n", tarifa);
	printf("Valor consumo (R$).:%.2lf\n", valorconsumo);
	printf("Taxas e impostos...:%.2lf\n", taxas);
	printf("Servicos...........:%.2lf\n", servicos);
	printf("TOTAL (R$).........:%.2lf\n", total);
}
