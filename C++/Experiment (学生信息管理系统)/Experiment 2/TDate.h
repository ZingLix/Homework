#pragma once
//#ifndef TDATE
#include <iostream>
#include <fstream>
using namespace std;
class TDate {
public:
	TDate();
	TDate(int y, int m, int d);
	void Display();
	void SetDate(int y, int m, int d);
	void SetValue();

	virtual void ReadFile(ifstream & InFile); //���ļ�
	virtual void WriteFile(ofstream & OutFile); //�ļ�����

private:
	int Year, Month, Day;
};
//#endif // !TDATE
