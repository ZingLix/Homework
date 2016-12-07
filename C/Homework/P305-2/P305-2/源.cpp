#include <stdio.h>
#include <stdlib.h>

double* GetWeigh2(double x[4][3]) {
	double *y = (double *)malloc(4 * sizeof(double));
	for (int i = 0; i < 4; i++) {
		y[i]=x[i][0];
	}
	return y;
}

int main() {
	double x1[3] = { 12, 6.3, 2.2 },
	       x2[3] = { 13, 7.4, 3.3 },
		   x3[3] = { 14, 8.5, 4.4 },
		   x4[3] = { 15, 9.6, 5.5 };
	double x[4][3] = {
		{ 12, 6.3, 2.2 },
		{ 13, 7.4, 3.3 },
		{ 14, 8.5, 4.4 },
		{ 15, 9.6, 5.5 } };
	double* y = GetWeigh2(x);
	for (int i = 0; i < 4; i++) {
		printf("%lf\n", y[i]);
	}
	free(y);
	for (int i = 0; i < 4; i++) {
		printf("%lf\n", y[i]);
	}
	system("pause");
	return 0;
}