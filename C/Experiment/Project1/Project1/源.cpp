#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const char * a,const char* b) {
	for (int i = 0; a[i] != '\0'&&b[i] != '\0';i++) {
		if (a[i] < b[i]) {
			return 1;
		}
		else if (a[i] > b[i]) {
			return 0;
		}

	}
	if (strlen(a) < strlen(b)) {
		return 1;
	}
	else if(strlen(a)>strlen(b)) {
		return 0;
	}
	else {
		return 2;
	}
}

int compare_date(char *a, char*b) {
	char tmp1[5], tmp2[5];
	int t[3] = { 7,4,2 }, p[3] = {4,2,2};
	for (int i = 0; i < 3; i++) {
		strncpy(tmp1, a + t[i], p[i]);
		strncpy(tmp2, b + t[i], p[i]);
		if (compare(tmp1, tmp2) != -1) {
			return compare(tmp1, tmp2);
		}
	}

	return 2;
}

void swap(char **a, char**b) {
	char *tmp;
	for (int i = 0; i < 3; i++) {
	tmp = *(a+i);
	*(a + i) = *(b+i);
	*(b + i) = tmp;
	}
}

void sort(char * data[4][3], int n) {
	if (n != 2) {                                            //比较文件名与文件大小
		for (int i = 0; i < 3; i++) {
			for (int j = 3; j > i; j--) {
				if (compare(data[j][n], data[j - 1][n])) {
					swap(&data[j][0], &data[j - 1][0]);
				}
			}
		}
		if (n == 0) swap(&data[1][0], &data[2][0]);
	}
	else {                                                  //比较日期
		for (int i = 0; i < 3; i++) {
			for (int j = 3; j > i; j--) {
				if (compare_date(data[j][n], data[j - 1][n])) {
					swap(&data[j][0], &data[j - 1][0]);
				}
			}
		}
	}

}


int main() {
	FILE* fp = fopen("data.txt", "r");
	char* data[4][3];
	char a[1000];
	fgets(a, 1000, fp);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			data[i][j] = (char*)malloc(sizeof(char) * 11);
			fscanf(fp, "%s", data[i][j]);
		}
	}
	for (int m = 0; m < 3; m++) {
		sort(data, m);
		printf("File name\tFile size\tDate\n");
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				printf("%s\t\t", data[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}