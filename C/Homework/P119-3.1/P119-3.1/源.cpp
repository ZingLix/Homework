#include <stdlib.h>
#include <stdio.h>

int main() {
	float a = 100, b = 200, c = 400, d = 800;
	printf("\tTable of Olympics running distances    \n");
	printf("Meters\t\tKilometers\tYards\t\tMiles\n");
	printf("%f\t%f\t%f\t%f\n", a, a*0.001, a*1.094, a*0.0006215);
	printf("%f\t%f\t%f\t%f\n", b, b*0.001, b*1.094, b*0.0006215);
	printf("%f\t%f\t%f\t%f\n", c, c*0.001, c*1.094, c*0.0006215);
	printf("%f\t%f\t%f\t%f\n", d, d*0.001, d*1.094, d*0.0006215);
	system("pause");
	return 0;
}