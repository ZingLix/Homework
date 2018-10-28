//HDU 1575
#include <stdio.h>
#include <cstring>
#include <utility>
#include <array>

const int mod = 9973;

class Matrix
{
public:
	using Mat = std::array<std::array<int, 12>, 12>;

	Matrix(int size):data(),size(size) {
		for (auto arr : data) arr.fill(0);
	}

	void operator*=(Matrix& rhs) {
		Matrix c(size);
		for(int i=0;i<size;++i) {
			for(int j=0;j<size;++j) {
				for(int k=0;k<size;++k) {
					c.data[i][j] += data[i][k] * rhs.data[k][j];
					c.data[i][j] %= mod;
				}
			}
		}
		data = std::move(c.data);
	}

	void operator=(Matrix&& rhs) {
		data = std::move(rhs.data);
	}

	Mat data;
	int size;
};

Matrix&& pow(Matrix& a,int b) {

	Matrix c(a.size);
	for (int i = 0; i < c.size; ++i) c.data[i][i] = 1;

	while (b > 0)
	{
		if (b % 2)
			c *= a;
		b /= 2;
		a *= a;
	}
	return std::move(c);
}

int main() {

	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, k;
		scanf("%d %d", &n, &k);
		Matrix c(n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				scanf("%d", &c.data[i][j]);
		}
		c = pow(c, k);
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum = (sum + c.data[i][i]) % mod;
		printf("%d\n", sum);
	}

	return 0;
}