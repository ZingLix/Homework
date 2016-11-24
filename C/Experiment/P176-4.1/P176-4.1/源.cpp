#include <stdio.h>
#include <stdlib.h>
int main() {
	FILE * fp;
	fp = fopen("INTSECT.DAT", "r");
	double s1, s2, i1, i2;
	fscanf(fp, "%lf %lf", &s1, &i1);
	fscanf(fp, "%lf %lf", &s2, &i2);
	double x, y;
	if (s1 != s2) {
		x = (i2 - i1) / (s1 - s2);
		y = s1*x + i1;
		printf("s1=%lf\ni1=%lf\ns2=%lf\ni2=%lf\n", s1, i1, s2, i2);
		printf("Intersection point:(%lf,%lf)", x, y);
	}
	else {
		printf("Do not have an intersection point!");
	}
	system("pause");
	fclose(fp);
	return 0;
}