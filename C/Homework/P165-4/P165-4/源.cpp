#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926
int main() {
	double sum = 0;
	double f = 1, x = 1;
	int i = 1;
	do {
		sum += 1 / (2 * (double)i - 1)*f;
		f *= -1;
		x += 2;
		if (i == 10) {
			printf("After 10 calculations,the sum is %lf\n", sum);
			printf("The difference between them is %lf\n", sum - PI / 4);
		}
		else if (i == 100) {
			printf("After 100 calculations,the sum is %lf\n", sum);
			printf("The difference between them is %lf\n", sum - PI / 4);
		}
		else if (i == 1000) {
			printf("After 1000 calculations,the sum is %lf\n", sum);
			printf("The difference between them is %lf\n", sum - PI / 4);
		}
		else if (i == 10000) {
			printf("After 10000 calculations,the sum is %lf\n", sum);
			printf("The difference between them is %lf\n", sum - PI / 4);
		}
		else if (i == 100000) {
			printf("After 100000 calculations,the sum is %lf\n", sum);
			printf("The difference between them is %lf\n", sum - PI / 4);
		}
		i++;
	} while (i <= 100000);
	system("pause");
	return 0;
}