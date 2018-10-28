#include <cstdio>
#include <cmath>
#include <cstring>

int n;
long long dp[69];

int main()
{
	memset(dp, 9999999, sizeof(dp));
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i < 67; i++) {
		for (int j = 1; j < i; j++) {
			long long tmp = 2 * dp[j] + pow(2.0, i - j) - 1;
			if (tmp>0&&tmp < dp[i])
				dp[i] = tmp;
		}
	}
	while (~scanf("%d", &n))
		printf("%lld\n", dp[n]);
}
