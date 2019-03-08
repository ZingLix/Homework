//HDU 1331
#include <iostream>
#include <memory>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <map>

int d[25][25][25];
bool f[25][25][25];

int dp(int x, int y, int z)
{
	if (x <= 0 || y <= 0 || z <= 0)
		return 1;
	if (x > 20 || y > 20 || z > 20)
		return dp(20, 20, 20);
	if (f[x][y][z])
		return d[x][y][z];
	if (x < y && y < z)
	{
		d[x][y][z] = dp(x, y, z - 1) + dp(x, y - 1, z - 1) - dp(x, y - 1, z);
		f[x][y][z] = true;
		return d[x][y][z];
	}
	d[x][y][z] = dp(x - 1, y, z) + dp(x - 1, y - 1, z) + dp(x - 1, y, z - 1) - dp(x - 1, y - 1, z - 1);
	f[x][y][z] = true;
	return d[x][y][z];
}

int main()
{
	int a, b, c;
	map.insert(std::make_pair(std::make_tuple(20, 20, 20), 1048576));
	while (true)
	{
		std::cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}
}
