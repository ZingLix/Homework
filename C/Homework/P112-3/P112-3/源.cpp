#include <stdio.h>
#include <stdlib.h>
int main(){
	FILE* fp;
	fp=fopen("GRADE.REP", "r");
	float a, b, c, d,average;
	fscanf(fp, "%f %f %f %f", &a, &b, &c, &d);
	average = (a + b + c + d) / 4;
	printf("%.1f %.1f %.1f %.1f\naverage GPA = %f\n", a, b, c, d, average);
	fclose(fp);
	system("pause");
	return 0;
}