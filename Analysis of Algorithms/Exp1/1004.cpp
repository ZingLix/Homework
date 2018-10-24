//HDU 1331
#include <iostream>
#include <memory>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <map>

std::map<std::tuple<int, int, int>, int> map;

int w(int a,int b,int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return map[std::make_tuple(20, 20, 20)];
	auto it = map.find(std::make_tuple(a, b, c));
	if (it != map.end()) return it->second;
	int res=0;
	if (a < b&&b < c) {
		int tmp = w(a, b, c - 1);
		map.insert(std::make_pair(std::make_tuple(a, b, c - 1), tmp));
		res += tmp;
		tmp = w(a, b - 1, c - 1);
		map.insert(std::make_pair(std::make_tuple(a, b - 1, c - 1), tmp));
		res += tmp;
		tmp = w(a, b - 1, c);
		map.insert(std::make_pair(std::make_tuple(a, b - 1, c), tmp));
		res -= tmp;
	}
	else {
		int tmp = w(a - 1, b, c);
		map.insert(std::make_pair(std::make_tuple(a - 1, b, c), tmp));
		res += tmp;
		tmp = w(a - 1, b - 1, c);
		map.insert(std::make_pair(std::make_tuple(a - 1, b - 1, c), tmp));
		res += tmp;
		tmp = w(a - 1, b, c - 1);
		map.insert(std::make_pair(std::make_tuple(a - 1, b, c - 1), tmp));
		res += tmp;
		tmp = w(a - 1, b - 1, c - 1);
		map.insert(std::make_pair(std::make_tuple(a - 1, b - 1, c - 1), tmp));
		res -= tmp;
	}
	return res;
}

int main() {
	int a, b, c;
	map.insert(std::make_pair(std::make_tuple(20, 20, 20), 1048576));
	while (true) {
		std::cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}
}
