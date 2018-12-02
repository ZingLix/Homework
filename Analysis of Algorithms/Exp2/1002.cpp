//HDU 1501
#include <iostream>
#include <string>
#include <unordered_map>
#include <cstdlib>
std::string str1, str2, str;

using iterator = std::string::iterator;
bool visit[201][201];

bool flag = false;

void test(int it1, int it2, int it) {
	if (visit[it1][it2]) return;
	if (it == str.length()) {
		flag = true;
		return;
	}
	visit[it1][it2] = true;

	if (it1 != str1.length() && str[it] == str1[it1]) {
		test(it1 + 1, it2, it + 1);
	}
	if (it2 != str2.length() && str[it] == str2[it2]) {
		test(it1, it2 + 1, it + 1);
	}
}

int main(int argc, char* argv[]) {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		flag = false;
		memset(visit, false, sizeof(visit));
		std::cin >> str1 >> str2 >> str;
		test(0, 0, 0);
		std::cout << "Data set " << i << ": ";
		std::cout << ((flag) ? "yes" : "no") << std::endl;

	}
	return 0;
}
