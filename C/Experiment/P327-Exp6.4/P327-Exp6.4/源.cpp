#include<stdio.h>
#include <stdlib.h>

void compress(FILE* fp) {
	FILE* tmp = fopen("data_compressed.txt", "w");
	char a = fgetc(fp);
	int count=1;
	char flag = a;
	while (a != EOF) {
		a = fgetc(fp);
		if (a == flag) {
			count++;
		}
		else {
			fprintf(tmp, "%d ", count);
			count=1;
			flag = a;
		}
	}
	fclose(tmp);
}

void decode(FILE *fp) {
	FILE *tmp = fopen("data_decoded.txt", "w");
	int x;
	int flag = 0;
	while (fscanf(fp,"%d", &x) != EOF) {
		for (int i = 0; i < x; i++) {
			fprintf(tmp,"%d", flag);
		}
		if (flag == 0)flag = 1;
		else flag = 0;
	}
}

int main()
{
	FILE* fp = fopen("data.txt", "r");
	compress(fp);
	fclose(fp);
	fp = fopen("data_compressed.txt", "r");
	decode(fp);
	fclose(fp);
	system("pause");
	return 0;
}