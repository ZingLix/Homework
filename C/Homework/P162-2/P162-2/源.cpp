#include <stdio.h>
#include <stdlib.h>

int main() {
	int i = 1, fac = 1;
	while (i <= 8) fac *= i++;
	printf("%d", fac);
	system("pause");
	return 0;
}