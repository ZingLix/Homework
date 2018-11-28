//HDU 1257
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <set>

int main(int argc, char* argv[]) {
	int n;
	while (std::cin >> n) {
		std::vector<int> height;
		while (n--) {
			int h;
			std::cin >> h;
			height.push_back(h);
		}
		n = 0;
		std::multiset<int> cur_max_height;
		for (auto h : height) {
			int f = false;
			for (auto it = cur_max_height.begin(); it != cur_max_height.end(); ++it) {
				if (*it > h) {
					cur_max_height.erase(it);
					cur_max_height.insert(h);
					f = true;
					break;
				}
			}
			if (!(f)) cur_max_height.insert(h);
		}
		std::cout << cur_max_height.size() << std::endl;
	}
}
