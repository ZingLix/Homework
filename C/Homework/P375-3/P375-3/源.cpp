#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char name[50], email[50];
	FILE *fp = fopen("data.txt", "w");
	gets_s(name);
	gets_s(email);
	printf("Name:%s\nEmail:%s\n\n", name, email);
	fprintf(fp, "%s\n%s", name, email);
	fclose(fp);
	name[0] = '\0';
	fp = fopen("data.txt", "r");
	rewind(fp);
	fgets(name,50,fp);
	fgets(email, 50, fp);
	name[strlen(name) - 1] = '\0';
	printf("*********************\n");
	printf("Name:%s\nEmail:%s\n", name, email);
	printf("*********************\n");
	system("pause");
	return 0;
}
