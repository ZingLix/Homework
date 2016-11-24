#include <stdio.h>
#include <stdlib.h>

void GetMax(int a, int b, int c, int* max);

int main() {
	int a, b, c, max;
	scanf("%d %d %d", &a, &b, &c);
	GetMax(a, b, c, &max);
	printf("%d", max);
	system("pause");
	return 0;
}

void GetMax(int a, int b, int c, int *max) {
	*max = a;
	if (*max < b) *max = b;
	if (*max < c) *max = c;
}