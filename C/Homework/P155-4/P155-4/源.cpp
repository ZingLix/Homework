#include <stdio.h>
#include <stdlib.h>
int main() {
	double income, tax;
	scanf("%lf", &income);
	int i = income / 1000;
	switch (i) {
	case 0: tax = 0.2*income; break;
	case 1:tax = 0.3*income; break;
	default:tax = 0.4*income;
	}
	printf("Tax is %.2lf", tax);
	system("pause");
 
}