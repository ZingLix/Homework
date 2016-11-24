#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
	double a, b, c, delta, x1, x2;
	scanf("%lf %lf %lf", &a, &b, &c);
	if (a == 0) {
		printf("x=%lf\n", -c / b);
	}
	else {
		delta = b*b - 4 * a*c;
		if (delta == 0) {
			printf("x1=x2=%lf\n", -b / 2 / a);
		}
		else if (delta > 0) {
			delta = sqrt(delta);
			x1 = (-b + delta) / (2 * a);
			x2 = (-b - delta) / (2 * a);
			printf("x1=%lf\nx2=%lf", x1, x2);
		}
		else {
			delta = sqrt(-delta);
			printf("x1= %lf + %lf i\n", -b / 2 / a, delta / 2 / a);
			printf("x1= %lf - %lf i\n", -b / 2 / a, delta / 2 / a);
		}
	}
	system("pause");
	return 0;
}