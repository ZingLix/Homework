#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int t = 10;
	double aver=0;
	for (int i = 1; i <= t; i++) {
		aver += i;
	}
	aver = aver/t;
	double variance=0;
	for (int i = 1; i <= t; i++) {
		variance += pow(i - aver, 2);
	}
	variance /= t;
	double deviation = sqrt(variance);
	printf("The mean is %lf\n", aver);
	printf("THe variance is %lf\n", variance);
	printf("The standard deviation is %lf\n", deviation);
	system("pause");
	return 0;

}
