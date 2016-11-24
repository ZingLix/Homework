#include <stdio.h>
#include <stdlib.h>

int main() {
	double horiz, verti, area;
	horiz = 5;
	verti = 7;
	printf("i\tarea\thorizleg\tvertleg\n");
	for (int i = 0; i < 4; i++) {
		area = 0.5*horiz*verti;
		printf("%d\t%.3lf\t%.3lf\t\t%.3lf\n",1+i,area,horiz,verti);
		horiz += 1;
		verti /= 2;
	}
	system("pause");
	return 0;
}