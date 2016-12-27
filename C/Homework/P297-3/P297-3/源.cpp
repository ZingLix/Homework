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
	int i = 0, j = 0;
	while (i < 2) {
		j = 0;
		while (j < 3) {
			printf("%d ", b[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	system("pause");
	return 0;
}