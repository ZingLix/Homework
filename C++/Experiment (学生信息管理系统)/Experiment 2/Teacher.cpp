#include "Teacher.h"

Teacher::Teacher()
{
	Title = "\0";
	Dept = "\0";
}

Teacher::Teacher(int id, string strName, string strSex, int y, int m, int d, string strTitle, string strDept)
//	:Person(id, strName, strSex, y, m, d), Title(strTitle), Dept(strDept)
{
	SetTeacher(id, strName, strSex, y, m, d, strTitle, strDept);
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

void Teacher::SetTeacher(int id, string strName, string strSex, int y, int m, int d, string strTitle, string strDept)
{
	Person::SetPerson(id, strName, strSex, y, m, d);
	Title = strTitle;
	Dept = strDept;
}
