#include <stdio.h>
#include <stdlib.h>

int main() {
	int S, D, unemployed = 0;
	for (int Y = 1990; Y <= 2010; Y++) {
		S = 1000 + 50 * (Y - 1990);
		if (Y <= 1995) {
			D = 1200;
		}
		else {
			D = 1200 + 60 * (Y - 1995);
		}
		printf("Year %d  Demand:%d Supply: %d", Y, D, S);
		if (S < D) {
			printf("\tNot enough!\n");
		}
		else {
			printf("\tEnough!\n");
			unemployed += S - D;
		}
	}
	printf("The total number of unemployed C programmers:%d", unemployed);
	system("pause");
	return 0;
}