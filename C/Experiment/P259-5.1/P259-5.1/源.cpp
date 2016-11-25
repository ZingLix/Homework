#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y) {
	if (x % y == 0) return y;
	else return gcd(y, x%y);
}

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	if (x < y) {
		int tmp = x;
		x = y;
		y = tmp;
	}
	int g = gcd(x, y);
	printf("%d", g);
	system("pause");
	return 0;
}