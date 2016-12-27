#include <stdio.h>
#include <string.h>

int main() {
	char x[54] = { '\0' };
	for (int i = 1; i <= 26; i++) {
		x[i - 1] = i % 10 + '0';
	}
	x[26] = '*';
	for (int i = 26; i >= 1; i--) {
		x[53 - i] = i % 10 + '0';
	}
	puts(x);


	for (char ch = 'A'; ch <= 'Z'; ch++) {
		for (int i = 0; i < 26; i++) {
			if (i <= ch - 'A') x[i]=ch;
			else x[i] = ' ';
		}
		for (int i = 25; i >= 0; i--) {
			if (i <= ch - 'A') x[52-i]=ch;
			else x[52 - i] = ' ';
		}
		puts(x);
	}


	for (int i = 1; i <= 26; i++) {
		x[i - 1] = i % 10 + '0';
	}
	x[26] = '*';
	for (int i = 26; i >= 1; i--) {
		x[53 - i] = i % 10 + '0';
	}
	puts(x);

	return 0;
}