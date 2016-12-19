#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void All_To_Upper(char * str, int size) {
	for (int i = 0; i < size; i++) {
		if (str[i] >= 'a'&&str[i] <= 'z') {
			str[i] -= 32;
		}
	}
}

void To_Lower(char * ch) {
	if (*ch >= 'A'&&*ch <= 'Z') {
		*ch += 32;
	}
}

void change(char * str, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0 || str[i - 1] == ' ') {
			All_To_Upper(&str[i], 1);
		}
		else {
			To_Lower(&str[i]);
		}
	}
}

int main() {
	char * name[4];
	for (int i = 0; i < 4; i++) {
		name[i] = (char *)malloc(sizeof(char) * 12);
	}
	strcpy_s(name[0], 12, "peTer Dodge");
	strcpy_s(name[1], 12, "kEith hill");
	strcpy_s(name[2], 12, "erIc randy");
	strcpy_s(name[3], 12, "lisa freDo");
	printf("Change a:\n");
	for (int i = 0; i < 4; i++) {
		change(name[i], strlen(name[i]));
		printf("%s\n", name[i]);
	}
	printf("Change b:\n");
	for (int i = 0; i < 4; i++) {
		All_To_Upper(name[i], strlen(name[i]));
		printf("%s\n", name[i]);
	}
	system("pause");
	return 0;
}