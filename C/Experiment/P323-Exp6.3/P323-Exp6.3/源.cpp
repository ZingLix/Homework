#include <stdio.h>
#include <stdlib.h>

int main() {
	int x[30][30], y[30];
	FILE *fp = fopen("data.txt", "r");
	int m, n;
	fscanf(fp, "%d %d", &m, &n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			fscanf(fp, "%d", &x[i][j]);
		}
		fscanf(fp, "%d", &y[i]);
	}
	for (int i = m; i< n; i++) { 
		fscanf(fp, "%d", &y[i]);
	}
	int sum ;
	for (int i = 0; i < m; i++) {
		sum = 0;
		for (int j = 0; j < n; j++) {
			sum += x[i][j] * y[j];
		}
		printf("%d\n", sum);
	}
	system("pause");
	return 0;
}