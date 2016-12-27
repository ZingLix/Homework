#include <stdio.h>
#include <stdlib.h>

double GetWeight1(double length, double width, double thickness) {
	length *= 0.3048;
	width *= 0.3048;
	thickness *= 2.54 / 100;
	return length*width*thickness * 7800;
}

double GetWeight2(double data[3]) {
	data[0] *= 0.3048;
	data[1] *= 0.3048;
	data[2] *= 2.54 / 100;
	return data[0]*data[1]*data[2] * 7800;
}

int main() {
	double x1[3] = { 12, 6.3, 2.2 },
	       x2[3] = { 13, 7.4, 3.3 },
		   x3[3] = { 14, 8.5, 4.4 },
		   x4[3] = { 15, 9.6, 5.5 };
	double weight[4];
	weight[0] = GetWeight1(x1[0], x1[1], x1[2]);
	weight[1] = GetWeight1(x2[0], x2[1], x2[2]);
	weight[2] = GetWeight1(x3[0], x3[1], x3[2]);
	weight[3] = GetWeight1(x4[0], x4[1], x4[2]);
	for (int i = 0; i < 4; i++) {
		printf("weight[%d]=%lf\n", i, weight[i]);
	}
	printf("\n");
	double x[4][3] = {
		{ 12, 6.3, 2.2 },
		{ 13, 7.4, 3.3 },
		{ 14, 8.5, 4.4 },
		{ 15, 9.6, 5.5 } };
	double weight2[4];
	for (int i = 0; i < 4; i++) {
		weight2[i] = GetWeight2(x[i]);
	}
	for (int i = 0; i < 4; i++) {
		printf("weight2[%d]=%lf\n", i, weight[i]);

	}

	system("pause");
	return 0;
}