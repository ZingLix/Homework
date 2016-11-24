#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("Before the change:a=%d b=%d\n", a, b);
	swap(&a, &b);
	printf("After the change:a=%d b=%d\n", a, b);
	system("pause");
	return 0;
}

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}