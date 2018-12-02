//HDU 1505
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

uint64_t lr(vector<uint64_t>& heights) {
	uint64_t res = 0;
	stack<uint64_t> st;
	heights.push_back(0);
	for (uint64_t i = 0; i < heights.size(); ++i) {
		while (!st.empty() && heights[st.top()] >= heights[i]) {
			uint64_t cur = st.top(); st.pop();
			res = max(res, heights[cur] * (st.empty() ? i : (i - st.top() - 1)));
		}
		st.push(i);
	}
	return res;
}

int main()
{
	uint64_t n;
	vector<uint64_t> height;
	height.reserve(100003);
	while (true)
	{
		std::cin >> n;
		if (n == 0) break;
		for(int i=0;i<n;++i) {
			int t;
			std::cin >> t;
			height.push_back(t);
		}
		height.push_back(0);
		std::cout << lr(height) << std::endl;
		height.clear();
	}
	return 0;
}
