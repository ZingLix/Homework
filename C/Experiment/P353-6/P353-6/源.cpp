#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE*fp = fopen("EX7_1_6.OUT", "w");
	char x[54] = { '\0' };
	for (int i = 1; i <= 26; i++) {
		x[i - 1] = i % 10 + '0';
	}
	x[26] = '*';
	for (int i = 26; i >= 1; i--) {
		x[53 - i] = i % 10 + '0';
	}
	fputs(x,fp);
	fputc('\n', fp);

	for (char ch = 'A'; ch <= 'Z'; ch++) {
		for (int i = 0; i < 26; i++) {
			if (i <= ch - 'A') x[i] = ch;
			else x[i] = ' ';
		}
		for (int i = 25; i >= 0; i--) {
			if (i <= ch - 'A') x[52 - i] = ch;
			else x[52 - i] = ' ';
		}
		fputs(x,fp);
		fputc('\n', fp);
	}


	for (int i = 1; i <= 26; i++) {
		x[i - 1] = i % 10 + '0';
	}
	x[26] = '*';
	for (int i = 26; i >= 1; i--) {
		x[53 - i] = i % 10 + '0';
	}
	fputs(x,fp);
	fputc('\n', fp);
	system("pause");
	return 0;
}