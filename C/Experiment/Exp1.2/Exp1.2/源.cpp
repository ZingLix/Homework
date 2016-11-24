#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	srand((unsigned int)time(NULL));
	int x;
	FILE* fp;
	fp = fopen("NUMBER.TXT", "w+");
	for (int i = 0; i < 10; i++) {
		x = rand() % 11 + 10;
		fprintf(fp, "%d ", x);
	}
	rewind(fp);
	for (int i = 0; i < 10; i++) {
		fscanf(fp, "%d ", &x);
		printf("%d ", x);
	}
	fclose(fp);
	system("pause");
	return 0;
}