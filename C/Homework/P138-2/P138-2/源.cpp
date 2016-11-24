#include <stdio.h>
#include<stdlib.h>
int main() {
	double income,tax;
	FILE* fp;
	fp = fopen("income.txt", "r");
	for (int i = 0; i < 10; i++) {
		fscanf(fp, "$%lf\n", &income);
		if (income < 1000) {
			printf("income = %d\ttax=0\n",(int)income);
		}
		else if (income >= 1000 && income < 2500) {
			tax = income / 4;
			printf("income = %d\ttax=%.1lf\n", (int) income,tax);
		}
		else {
			tax = 500 + 0.3*income;
			printf("income = %d\ttax=%.1lf\n", (int)income,tax);
		}
	}
	system("pause");
	return 0;
}