#include <stdio.h>
#include <stdlib.h>

int main() {
	int p ;
	scanf("%d", &p);
	for (int i = 1; i <= p;i ++) {
		for (int j = 1; j <= p; j++) {
			if (j < i) {
				printf("   ");
			}
			else {
				printf("%3d", i*j);
			}
		}
		printf("\n");
	}
	system("pause");
	return 0;
}