#include <stdio.h>

int main() {
	char flag;
	double f, c, i;
	while (1) {
		printf("Please input the term of the temperature:");
		scanf("%lf%c", &i,&flag);
		if (flag == 'c'|| flag == 'C') {
			c = i;
			f = c * 9 / 5 + 32;
			printf("The degrees Fahrenheit is %lfF\n", f);
		}
		else if (flag == 'f'|| flag == 'F') {
			f = i;
			c = (f - 32) * 5 / 9;
			printf("The degrees Celsius is %lfC\n", c);
		}
		else {
			break;
		}
	}
	return 0;
}