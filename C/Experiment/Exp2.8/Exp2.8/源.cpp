#include <stdio.h>
#include <stdlib.h>

int main() {
	int flag = 0;
	for (int i = 101; i <= 200; i += 2) {
		for (int j = 2; j <= i / 2; j++) {
			if (i%j == 0)  flag = 1; 
		}
		if (flag == 0) {
			printf("%d\n", i);
		}
		flag = 0;
	}
	system("pause");
	return 0;
}