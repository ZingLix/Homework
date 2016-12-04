#include <stdio.h>
#include <stdlib.h>

int main() {
	int a[3][2] = { 11,22,33,44,55,66 };
	int b[2][3] = { 111,222,333,444,555,666 };
	printf("Matrix a:\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\nMatrix b:\n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}