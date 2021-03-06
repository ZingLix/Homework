#include "Teacher.h"

Teacher::Teacher()
{
	Title = "\0";
	Dept = "\0";
}

Teacher::Teacher(string strName, string strSex, int y, int m, int d, string strTitle, string strDept)
	:Person(strName, strSex, y, m, d), Title(strTitle), Dept(strDept)
{
//	SetTeacher(strName, strSex, y, m, d, strTitle, strDept);
}

void Teacher::Display()
{
	Person::Display();
	cout << "职称：" << Title << endl;
	cout << "所在系：" << Dept;
}

void Teacher::SetValue()
{
	Person::SetValue();
	cout << "职称：";
	cin >> Title;
	cout << "所在系：";
	cin >> Dept;
}

void Teacher::SetTeacher(string strName, string strSex, int y, int m, int d, string strTitle, string strDept)
{
	Person::SetPerson(strName, strSex, y, m, d);
	Title = strTitle;
	Dept = strDept;
}

void Teacher::ReadFile(ifstream & InFile)
{
	Person::ReadFile(InFile);
	InFile >> Title >> Dept;
}

void Teacher::WriteFile(ofstream & OutFile)
{
	Person::WriteFile(OutFile);
	OutFile << Title << " " << Dept;
}
