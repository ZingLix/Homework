#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double GetMod(double vec[3]) {
	double mod = 0;
	for (int i = 0; i < 3; i++) {
		mod += vec[i] * vec[i];
	}
	return sqrt(mod);
}

double GetDotProduct(double x[3], double y[3]) {
	double dp = 0;
	for (int i = 0; i < 3; i++) {
		dp += x[i] * y[i];
	}
	return dp;
}

int main() {
	double vec[3][3];
	double vol = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%lf", &vec[i][j]);
		}
	}

	double mod[3],cos_ab;
	for (int i = 0; i < 3; i++) {
		mod[i] = GetMod(vec[i]);
	}

	cos_ab = GetDotProduct(vec[0], vec[1]) / (mod[0] * mod[1]);
	vol = mod[0] * mod[1] * sqrt(1 - cos_ab*cos_ab);

	double vertical_vec[3];
	for (int i = 0; i < 3; i++) {
		int x=(i+1)%3, y=(i+2)%3;
		vertical_vec[i] = vec[0][x] * vec[1][y] - vec[0][y] * vec[1][x];
	}

	double high = GetDotProduct(vertical_vec,vec[2])/GetMod(vertical_vec);
	vol *= high;

	printf("%lf\n", fabs(vol));
	system("pause");
	return 0;
}