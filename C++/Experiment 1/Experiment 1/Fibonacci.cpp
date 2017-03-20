#include "Fibonacci.h"

Fibonacci::Fibonacci(int n):n(n)
{
	p = new int*[n];
	p[0] = new int[1];
	p[0][0] = 1;
	for (int i = 1; i < n; i++) {
		p[i] = new int[i+1];
		p[i][0] = 1;
		p[i][1] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 2; j <= i; j++) {
			p[i][j] = p[i][j - 1] + p[i][j - 2];
		}
	}
}

Fibonacci::~Fibonacci()
{
	for (int i = 0; i < n; i++) {
		delete[]p[i];
	}
	delete []p;
}

void Fibonacci::show()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
}
