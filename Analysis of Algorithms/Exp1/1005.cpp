//HDU 2018
#include <iostream>
#include <array>

std::array<int, 55> ans;

int main() {
	ans.fill(0);
	ans[1] = 1;
	ans[2] = 2;
	ans[3] = 3;
	ans[4] = 4;
	for(int x=5;x<55;++x) {
		ans[x] = ans[x - 1] + ans[x - 3];
	}
	while (true) {
		int n;
		std::cin >> n;
		if(n==0) break;
		printf("%d\n", ans[n]);
	}
}
