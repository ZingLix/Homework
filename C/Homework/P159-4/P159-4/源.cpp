#include <stdio.h>
#include <stdlib.h>

int main() {
	int p;
	scanf("%d", &p);
	int flag = 0;
	for (int i = 2; i <= p / 2; i++) {
		if (p%i == 0) flag = 1;
	}
	if (flag == 0) { 
		printf("%d is a prime number.", p);
	}
	else {
		printf("%d is not a prime number.", p);
	}
	system("pause");
	return 0;
}