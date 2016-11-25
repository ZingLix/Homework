#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 8
/*
int check(int i, int j) {
	int counter = 0;
	if (i - 2 >= 0) {
		if (j + 1 >= 0) counter++;
		if (j - 1 >=  0) counter++;
	}
	if (i - 1 >= 0) {
		if (j + 2 >= 0) counter++;
		if (j - 2 >= 0) counter++;
	}
	if (i + 2 >= 0) {
		if (j + 1 >= 0) counter++;
		if (j - 1 >= 0) counter++;
	}
	if (i + 1 >= 0) {
		if (j + 2 >= 0) counter++;
		if (j - 2 >= 0) counter++;
	}
	return counter;
}
*/
int check(int i, int j) {
	int counter = 0;
	int n;
	for (int m = -2; m <= 2; m++) {
		if (m == 0) continue;
		n = 3 - abs(m);
		if (i + m >= 0) {
			if (j + n >= 0) counter++;
			if (j - n >= 0) counter++;
		}
	}
	return counter;
}
int main() {
	int chess[SIZE][SIZE] = {0};
	for (int i = 0; i < SIZE/2; i++) {
		for (int j = 0; j < SIZE/2; j++) {
			chess[i][j] = check(i, j);
			chess[i][SIZE-1 - j] = chess[i][j];
			chess[SIZE - 1 - i][j] = chess[i][j];
			chess[SIZE - 1 - i][SIZE-1 - j] = chess[i][j];
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%d ", chess[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}