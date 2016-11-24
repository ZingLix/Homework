#include <stdio.h>
#include <stdlib.h>

int main() {
	int x;
	scanf("%d", &x);
	for (int i = 1; i <= (x+1)/2; i++) {
		for (int j = (x+1)/2-i; j > 0; j--) {
			printf(" ");
		}
		for (int j = 0; j < 2 * i - 1; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = 1; i < (x + 1) / 2; i++) {
		for (int j = i; j > 0; j--) {
			printf(" ");
		}
		for (int j = 1; j < x-(2 * i - 1); j++) {
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}