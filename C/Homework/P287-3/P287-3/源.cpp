#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926

int main() {
	FILE *fp = fopen("data.txt", "r");
	double data[4],b;
	int a;
	for (int i = 0; i < 4; i++) {
		fscanf(fp, "%d %lf", &a, &b);
		data[a-1] = b;
	}
	printf("N\tX(degree)\tcos(X)\n");
	for (int i = 0; i < 4; i++) {
		printf("%d\t%.1lf\t\t%.4lf\n", i, data[i], cos(data[i] / 180 * PI));
	}
	system("pause");
	return 0;
}