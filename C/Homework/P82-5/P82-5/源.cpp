#include <stdio.h>
#include <stdlib.h>
void main() {
	float a = 2.5, b = 2, c = 3, d = 4, e = 5, x, y, z;
	x = a*b - c + d / e;
	y = a*(b - c) + d / e;
	z = a*(b - (c + d) / e);
	printf("x= %10.3f, y= %10.3f,z= %10.3f", x, y, z);
	system("pause");
}