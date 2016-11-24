#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define STEP 0.001
int main() {
	double  y;
	double distance = 0;
	double min = 100;
	for (double x = 0.111; x < 10; x += STEP) {
		y = sqrt(54 / x);
		distance = x*x + y*y;
		if (min > distance) {
			min = distance;
		}
	}
	printf("The minimun of x^2+y^2 is %lf", sqrt(min));
	system("pause");
	return 0;
}