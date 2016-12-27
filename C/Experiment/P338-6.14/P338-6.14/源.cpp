#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand((unsigned)time(NULL));
	int a, b;
	printf("Roll your first die!");
	getchar();
	a = rand() % 6 + 1;
	printf("You got %d!\n", a);
	printf("Roll your second die!");
	getchar();
	b = rand() % 6 + 1;
	printf("You got %d!\n", b);
	int sum = a + b;
	printf("The sum is %d\n", sum);
	switch (sum)
	{
	case 7:printf("You win!\n"); break;
	case 11:printf("You lose!\n"); break;
	default:printf("You neither win nor lose!\n");
		break;
	}
	system("pause");
	return 0;
}