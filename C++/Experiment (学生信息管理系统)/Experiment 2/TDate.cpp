#include "TDate.h"

TDate::TDate()
{
	Year = 1970;
	Month = 1;
	Day = 1;
}

TDate::TDate(int y, int m, int d)
{
	Year = y;
	Month = m;
	Day = d;
}

void TDate::Display()
{
	cout << Year << "年" << Month << "月" << Day << "日";
}

void TDate::SetDate(int y, int m, int d)
{
	Year = y;
	Month = m;
	Day = d;
}

void TDate::SetValue()
{
	cout << "出生年份：";
	cin >> Year;
	cout << "出生月份：";
	cin >> Month;
	cout << "出生日期：";
	cin >> Day;
}

void TDate::ReadFile(ifstream & InFile)
{
	InFile >> Year >> Month>> Day ;
}

void TDate::WriteFile(ofstream & OutFile)
{
	OutFile << Year << " " << Month << " " << Day << " ";
}
