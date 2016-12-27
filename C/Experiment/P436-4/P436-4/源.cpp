#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int **data;
	data = (int **)malloc(sizeof(int*) * 400);
	for (int i = 0; i < 400; i++) {
		data[i] = (int *)malloc(sizeof(int) * 80);
	}
	srand((unsigned)time(NULL));
	int arr[10][30];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 30; j++) {
			arr[i][j] = rand() % 100;
		}
	}
	int x = 0, y = 0;
	for (int i = 0; i < 400; i++) {
		for (int j = 0; j < 80; j++) {
			data[i][j] = arr[x][y++];
			if (y == 30) {
				y = 0;
				x++;
				x %= 10;
			}
		}
	}
	FILE *fp = fopen("data.txt", "w");
	for (int i = 0; i < 400; i++) {
		for (int j = 0; j < 80; j++) {
			fprintf(fp,"%d ", data[i][j]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
	for (int i = 0; i < 400; i++) {
		free(data[i]);
	}
	free(data);
	system("pause");
	return 0;
}