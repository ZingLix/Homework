#include <stdio.h>

int main() {
	FILE* fp;
	fp = fopen("MONEY.OUT", "w");
	double rate,money=5000;
	scanf("%lf", &rate);
	rate /= 12;
	fprintf(fp,"Year\tMonth\tBalance\n");
	for (int year = 1; year <= 5; year++) {
		for (int month = 1; month <= 12; month++) {
			money *= (1 + rate);
			fprintf(fp,"%d\t%d\t%lf\n", year, month, money);
		}
	}
	return 0;
}