#include <stdio.h>
#include <stdlib.h>

int main() {
	for (int i = 1; i <= 26; i++) {
		printf("%d", i % 10);
	}
	printf("*");
	for (int i = 26; i >= 1; i--) {
		printf("%d", i % 10);
	}
	printf("\n");


	for (char x = 'A'; x <= 'Z'; x++) {
		for (int i = 0; i < 26; i++) {
			if (i <= x - 'A') printf("%c", x);
			else printf(" ");
		}
		printf("*");
		for (int i = 25; i >= 0; i--) {
			if (i <= x - 'A') printf("%c", x);
			else printf(" ");
		}
		printf("\n");
	}


	for (int i = 1; i <= 26; i++) {
		putchar(i%10+'0');
	}
	printf("*");
	for (int i = 26; i >= 1; i--) {
		printf("%d", i % 10);
	}
	printf("\n\n");



	for (int i = 1; i <= 26; i++) {
		putchar(i % 10 + '0');
	}
	printf("*");
	for (int i = 26; i >= 1; i--) {
		putchar(i % 10 + '0');
	}
	printf("\n");


	for (char x = 'A'; x <= 'Z'; x++) {
		for (int i = 0; i < 26; i++) {
			if (i <= x - 'A') putchar(x);
			else putchar(' ');
		}
		printf("*");
		for (int i = 25; i >= 0; i--) {
			if (i <= x - 'A') putchar(x);
			else putchar(' ');
		}
		printf("\n");
	}


	for (int i = 1; i <= 26; i++) {
		putchar(i % 10 + '0');
	}
	printf("*");
	for (int i = 26; i >= 1; i--) {
		putchar(i % 10 + '0');
	}
	printf("\n");

	system("pause");
	return 0;
}