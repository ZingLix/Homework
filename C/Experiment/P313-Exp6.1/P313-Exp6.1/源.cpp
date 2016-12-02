#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(char x[], char y[], const int n) {
	int tmp = 0;
	char ans[19] = {'\0'};
	x = _strrev(x);
	y = _strrev(y);
	for (int i = 0; i < n; i++) {
		ans[i] = (x[i] + y[i]+tmp-2*'0') % 2+'0';
		tmp = (x[i] + y[i] + tmp - 2 * '0' )/2;
	}
	ans[n] = tmp+'0';
	_strrev(ans);
	printf("%s\n", ans);
}

int main() {
	char x[17], y[17];
	gets_s(x);
	gets_s(y);
	add(x, y, 16);
	system("pause");
	return 0;
}

