#pragma once
#ifndef TDATE
#include <iostream>
using namespace std;
class TDate {
public:
	TDate();
	TDate(int y, int m, int d);
	void Display();
	void SetDate(int y, int m, int d);
	void SetValue();

private:
	int Year, Month, Day;
};
#endif // !TDATE
