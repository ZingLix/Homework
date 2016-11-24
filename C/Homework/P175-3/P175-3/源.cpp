#include <stdio.h>
#include <stdlib.h>
int main() {
	int a, b, c;
	for (a = 1; a < 3; a++) {
		c = a;
		for (b = 1; b < 3; b++) c += a + b;
		c += 10;
	}
	printf("%d", c);
	system("pause");
	return 0;
}