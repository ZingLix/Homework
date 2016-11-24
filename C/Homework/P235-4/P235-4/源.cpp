#include <stdio.h>
#include <stdlib.h>

void swap(int **a, int **b);

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int *x = &a, *y = &b;
	printf("Before the change:a=%d b=%d\n", *x, *y);
	swap(&x, &y);
	printf("After the change:a=%d b=%d\n", *x, *y);
	system("pause");
	return 0;
}

void swap(int **a, int **b) {
	int *tmp = *a;
	*a = *b;
	*b = tmp;
}