//HDU 1503
#include <iostream>
#include <string>

using namespace std;

std::string a, b;
int dp[101][101];
int mark[101][101];

void LCS(size_t lena, size_t lenb) {
	for (size_t i = 0; i < lena; ++i) {
		dp[i][0] = 0;
		mark[i][0] = 2;
	}
	for (size_t i = 0; i < lenb; ++i) {
		dp[0][i] = 0;
		mark[0][i] = 1;
	}
	for (size_t i = 1; i <= lena; ++i) {
		for (size_t j = 1; j <= lenb; ++j) {
			if (a[i-1] == b[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				mark[i][j] = 0;  //left up
			}
			else if (dp[i][j - 1] > dp[i - 1][j]) {
				dp[i][j] = dp[i][j - 1];
				mark[i][j] = 1;  //left
			}
			else {
				dp[i][j] = dp[i - 1][j];
				mark[i][j] = 2;  //up
			}
		}
	}
}

void print(size_t x, size_t y) {
	if (x==0 && y==0) return;
	if (mark[x][y] == 0) {
		print(x - 1, y - 1);
		std::cout << a[x - 1];
	}
	else if (mark[x][y] == 2) {
		print(x - 1, y);
		std::cout << a[x - 1];
	}
	else {
		print(x, y - 1);
		std::cout << b[y -1];
	}
}

int main()
{
	while (std::cin >> a >> b)
	{
		LCS(a.length(), b.length());
		print(a.length(), b.length());
		std::cout << std::endl;
	}
	return 0;
}
