//HDOJ 1106
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	std::string str;
	while (std::cin >> str) {
		std::vector<int> num;
		auto tmp = str.begin();
		for (auto it = str.begin(); it != str.end(); ++it) {
			if (*it == '5') {
				if(it!=tmp)
				num.push_back(std::stoi(std::string(tmp, it).c_str()));
				tmp = it+1;
			}
		}
		if(tmp!=str.end())
		num.push_back(std::stoi(std::string(tmp, str.end()).c_str()));
		std::sort(num.begin(), num.end());
		for (auto it = num.begin(); it != num.end(); ++it) {
			if (it != num.begin()) printf(" ");
			printf("%d", *it);
		}
		printf("\n");
	}
}