#pragma once
#ifndef FIBONACCI
#include <iostream>
using namespace std;

class Fibonacci {
public:
	Fibonacci(int i);
	~Fibonacci();
	void show();

private:
	int n;
	int **p;

};

#endif // !FIBONACCI
