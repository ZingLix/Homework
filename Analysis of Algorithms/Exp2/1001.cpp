//HDU 1500
#include <iostream>

int dp[1010][5005];
int main() {

	int t;
	std::cin >> t;
	while (t--) {
		int k, n;
		std::cin >> k >> n;
		int chop[5000];
		for (int i = n; i >0; --i) {
			std::cin >> chop[i];
		}
		for (int i = 0; i <= k + 8; i++)
		{
			for (int j = 0; j <= n; j++) {
				//dp[0][j] = 0;
				dp[i][j] = 32005;
			}
		}

		for (int j = 0; j <= n; j++)
			dp[0][j] = 0;

		for (int i = 1; i <= k + 8; ++i) {
			for (int j = 3 * i; j <= n; ++j) {
				if (dp[i][j - 1] > dp[i - 1][j - 2] + (chop[j] - chop[j - 1])*(chop[j] - chop[j - 1]))
					dp[i][j] = dp[i - 1][j - 2] + (chop[j] - chop[j - 1])*(chop[j] - chop[j - 1]);
				else
					dp[i][j] = dp[i][j - 1];
			}
		}
		std::cout << dp[k + 8][n]<<std::endl;
	}
}