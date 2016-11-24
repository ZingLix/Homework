#include <stdio.h>
#include <stdlib.h>
int main() {
	double sum=0;
	double f=1, x=1;
	int i = 1;
	while(i<=100000) {
		sum += 1 / (2*(double)i-1)*f;
		f *= -1;
		x += 2;
		if (i == 10) {
			printf("After 10 calculations,the sum is %lf\n", sum);
		}
		else if (i == 100) {
			printf("After 100 calculations,the sum is %lf\n", sum);
		}
		else if (i == 1000) {
			printf("After 1000 calculations,the sum is %lf\n", sum);
		}
		else if (i == 10000) {
			printf("After 10000 calculations,the sum is %lf\n", sum);
		}
		else if (i == 100000) {
			printf("After 100000 calculations,the sum is %lf\n", sum);
		}
		i++;
	}
	return 0;
}