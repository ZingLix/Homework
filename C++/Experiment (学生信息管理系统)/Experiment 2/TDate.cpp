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
	cout << Year << "��" << Month << "��" << Day << "��";
}

void TDate::SetDate(int y, int m, int d)
{
	Year = y;
	Month = m;
	Day = d;
}

void TDate::SetValue()
{
	cout << "������ݣ�";
	cin >> Year;
	cout << "�����·ݣ�";
	cin >> Month;
	cout << "�������ڣ�";
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
