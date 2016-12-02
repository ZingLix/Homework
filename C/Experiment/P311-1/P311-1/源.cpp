#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int*b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void BubbleSort(int A[], int n) {
	for (int i = n; i >0; i--) {
		for (int j = 0; j < i-1; j++) {
			if (A[j] > A[j + 1]) {
				swap(&A[j], &A[j + 1]);
			}
		}
	}
}

void ExchangeMaxSort(int A[], int n) {
	for (int i = n-1; i >= 0; i--) {
		int max = i;
		for (int j = i; j >= 0; j--) {
			if (A[j] > A[max]) max = j;
		}
		swap(&A[i], &A[max]);
	}
}

void ExchangeMinSort(int A[], int n) {
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i; j < n; j++) {
			if (A[j] < A[min]) min = j;
		}
		swap(&A[i], &A[min]);
	}
}

void RandomGeneration(int A[], int n) {
	for (int i = 0; i < 10; i++) {
		A[i] = rand() % 100;
	}
}

void PrintAll(int A[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

int main() {
	int x[10];
	srand((unsigned int)time(NULL));
	printf("Before the sort:\n");
	RandomGeneration(x, 10);
	PrintAll(x, 10);
	printf("After the bubble sort:\n");
	BubbleSort(x, 10);
	PrintAll(x, 10);
	printf("==========================\n");
	printf("Before the sort:\n");
	RandomGeneration(x, 10);
	PrintAll(x, 10);
	printf("After the exchange max sort:\n");
	ExchangeMaxSort(x, 10);
	PrintAll(x, 10);
	printf("==========================\n");
	printf("Before the sort:\n");
	RandomGeneration(x, 10);
	PrintAll(x, 10);
	printf("After the exchange min sort:\n");
	ExchangeMinSort(x, 10);
	PrintAll(x, 10);
	printf("\n");
	system("pause");
	return 0;
}