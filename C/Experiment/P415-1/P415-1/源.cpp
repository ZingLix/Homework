#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int match(char x) {
	char tokens[] = { '"','[',']','(',')','{','}','*',',',':','=',';','.','#','\t','\n','\\',' ' };
	for (int i = 0; i < 18; i++) {
		if (x == tokens[i]) return 1;
	}
	return 0;
}

int match_digit(char x[]) {
	for (int i = 0; i < strlen(x); i++) {
		if (x[i] >= '0'&&x[i] <= '9') return 1;
	}
	return 0;
}

int main() {
	FILE *fp = fopen("data.txt", "r");

	char x = 0;
	int count = 0;
	while(x!=EOF) {
		x = fgetc(fp);
		count += match(x);
	}
	printf("Number of tokens: %d\n", count);
	rewind(fp);
	char str[500];
	count = 0;
	char y;
	while (fscanf(fp,"%s", str) != EOF) {
		if (strcmp(str, "Good") == 0) count++;
	}
	printf("Number of \"GOOD\"=%d\n", count);
	rewind(fp);
	FILE *fnew = fopen("data_new.txt", "w");
	while (fscanf(fp,"%s", str) != EOF) {
		if (match_digit(str)) {
			atof(str);
		}
		fprintf(fnew,"%s", str);
		y = fgetc(fp);
		fputc(y, fnew);
	}
	system("pause");
	return 0;
}