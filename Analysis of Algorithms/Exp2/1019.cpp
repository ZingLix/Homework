//HDU 2037
#include <algorithm>
#include <iostream>
#include <array>

struct Time
{
	int start;
	int end;
};

bool cmp(Time a, Time b)
{
	return a.end < b.end;
}

int main()
{
	std::array<Time, 100> time;
	int n;
	while (std::cin>>n&&n!=0)
	{
		for (int i = 0; i < n; i++)
			std::cin >> time[i].start >> time[i].end;
		std::sort(time.begin(), time.begin()+n, cmp);
		int begin = 0;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (time[i].start >= begin)
			{
				sum++;
				begin = time[i].end;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}