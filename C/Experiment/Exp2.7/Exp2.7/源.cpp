#include <stdio.h>
#include <stdlib.h>
int main() {
	int x;
	double sum = 0, fac = 1;
	scanf("%d", &x);
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= i; j++) {
			fac *= j;
		}
		sum += fac;
		fac = 1;
	}
	printf("The sum is %.0lf\n", sum);
	system("pause");
	return 0;
}