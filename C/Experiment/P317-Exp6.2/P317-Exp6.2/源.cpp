#include <stdio.h>
#include <stdlib.h>

double GetMean(int x[], int n) {
	int sum=0;
	for (int i = 0; i < n; i++) {
		sum += x[i];
	}
	return 1.0*sum / n;
}

void swap(int *a, int*b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Sort(int A[], int n) {
	for (int i = n; i >0; i--) {
		for (int j = 0; j < i - 1; j++) {
			if (A[j] > A[j + 1]) {
				swap(&A[j], &A[j + 1]);
			}
		}
	}
}
int GetMedian(int x[], int n) {
	Sort(x, n);
	return x[(n + 1) / 2-1];
}

int main() {
	int x[30],n;
	FILE*fp = fopen("data.txt", "r");
	fscanf(fp, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(fp, "%d", &x[i]);
	}
	printf("Mean:%lf\n", GetMean(x, n));
	printf("Median:%d", GetMedian(x, n));
	system("pause");
	return 0;
}