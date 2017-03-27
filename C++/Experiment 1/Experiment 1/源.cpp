#include "Fibonacci.h"

int main() {
	int n;
	cout << "输入Fibonacci数列行数：";
	cin >> n;
	Fibonacci f(n);
	f.show();
	system("pause");
	return 0;
}