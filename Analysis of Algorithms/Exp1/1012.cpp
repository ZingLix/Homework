//HDU 2511
#include <cstdio>
#include <iostream>

long long times, cur;
long long a[64];

void hannoi(int n, long long  m, int from, int to) {
	if (n == 0) return;
	int buffer = 6 - from - to;
	long long mid = a[n-1];
	if (m == mid){
		std::cout << n << " " << from << " " << to << std::endl;
	return;
	}
	if (m < mid)
		hannoi(n - 1, m, from, buffer);
	else
		hannoi(n - 1, m - mid, buffer, to);
}


int main() {
	a[0] = 1;
	for (int i = 1; i < 64; ++i) {
		//a[i] = (a[i - 1] + 1) * 2 - 1;
		a[i] = 2*a[i-1];
	}
	int n;
	scanf("%d", &n);
	while (n--) {
		int x;
		cur = 1;
		scanf("%d %lld", &x, &times);
		hannoi(x, times, 1, 3);

	}
}