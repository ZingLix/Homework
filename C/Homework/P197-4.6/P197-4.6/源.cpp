#include <stdio.h>
#include <stdlib.h>
int main() {
	FILE * fp;
	fp = fopen("TWOMM.DAT", "r");
	int p1;
	fscanf(fp, "%d", &p1);
	int max = p1, secmax = p1;
	int min = p1, secmin = p1;
	fscanf(fp, "%d", &p1);
	if (p1 > max) {
		max = p1;
		secmin = p1;
	}
	else {
		secmax = p1;
		min = p1;
	}
	while (feof(fp)!=1) {
		fscanf(fp, "%d", &p1);
		if (p1 >= max) {
			secmax = max;
			max = p1;
		}
		else if (p1 >= secmax) {
			secmax = p1;
		}
		if (p1 <= min) {
			secmin = min;
			min = p1;
		}
		else if (p1 <= secmin) {
			secmin = p1;
		}
	}
	printf("The two largest:\n");
	printf("%d %d\n", max, secmax);
	printf("The two smallest:\n");
	printf("%d %d\n", min, secmin);
	system("pause");
	return 0;
}