#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(char * str,double flag[3]) {
	if (str[0] == 'd'&&str[1]=='='&&flag[0] == 0) {
		flag[0] = strtod(&str[2],NULL);
		return 1;
	}else if(str[0] == 'v'&&str[1] == '='&&flag[1] == 0) {
		flag[1] = strtod(&str[2], NULL);
		return 1;
	}
	else if (str[0] == 'D'&&str[1] == '='&&flag[2] == 0) {
		flag[2] = strtod(&str[2], NULL);
		return 1;
	}
	else {
		printf("Input error!\n");
		return 0;
	}
}

int main() {
	char str[10] = { '\0' };
	int count = 0;
	double flag[3] = { 0 };
	int bad=0;
	while (count != 3) {
		scanf("%s", str);
		if (check(str, flag)) {
			count++;
		}
		else {
			bad++;
			if (bad == 5) {
				printf("Having tried too much.\n");
				exit(0);
			}
		}

	}
	double V;
	V = flag[1] * flag[0] * flag[0] / flag[2] / flag[2];
	printf("The exit velocity for the fluid is %lf", V);

	system("pause");
	return 0;
}