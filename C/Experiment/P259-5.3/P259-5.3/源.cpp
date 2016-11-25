#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	double E, L,N, M1, M2;
	scanf("%lf%lf", &E,&L);
	M1 = (log(E)/log(10) - 11.8) / 1.5;
	M2 = (log(L)/log(10) + 5.77) / 1.02;
	if (M1 / M2 < 1.2&&M1 / M2>0 / 8) printf("Compatible!\n");
	else printf("Incompatible!\n");
	N = pow(10, 7.72 - 0.9*(M1 + M2) / 2);
	printf("The most likely numbers of earthquakes:%.0lf", N);
	system("pause");
	return 0;
}