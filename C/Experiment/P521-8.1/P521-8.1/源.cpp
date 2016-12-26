#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int*b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void quick_sort(int *x, int left, int right) {
	if (right - left > 0) {
		int j = left+1;
		for (int i = left+1; i <= right; i++) {
			if (x[i] < x[left]) swap(&x[i], &x[j++]);
		}
		swap(&x[left], &x[--j]);
		quick_sort(x, left, j - 1);
		quick_sort(x, j+1, right);
	}
	else {
		return ;
	}
}

int main() {
	srand((unsigned)time(NULL));
	int x[10000] = { 0 };
	for (int i = 0; i < 10000; i++) {
		x[i] = rand() % 10000;
	}
	quick_sort(x, 0, 9999);
	for (int i = 0; i < 10000; i++) {
		printf("%d \n", x[i]);
	}
	system("pause");
	return 0;
}