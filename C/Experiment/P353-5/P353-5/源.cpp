#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE*fp = fopen("EX7_1_5.OUT", "w");
	for (int i = 1; i <= 26; i++) {
		fprintf(fp,"%d", i % 10);
	}
	fprintf(fp,"*");
	for (int i = 26; i >= 1; i--) {
		fprintf(fp,"%d", i % 10);
	}
	fprintf(fp,"\n");


	for (char x = 'A'; x <= 'Z'; x++) {
		for (int i = 0; i < 26; i++) {
			if (i <= x - 'A') fprintf(fp,"%c", x);
			else fprintf(fp," ");
		}
		fprintf(fp,"*");
		for (int i = 25; i >= 0; i--) {
			if (i <= x - 'A') fprintf(fp,"%c", x);
			else fprintf(fp," ");
		}
		fprintf(fp,"\n");
	}


	for (int i = 1; i <= 26; i++) {
		fprintf(fp, "%d", i % 10);
	}
	fprintf(fp,"*");
	for (int i = 26; i >= 1; i--) {
		fprintf(fp,"%d", i % 10);
	}
	fprintf(fp,"\n\n");




	system("pause");
	return 0;
}