#include "Teacher.h"

Teacher::Teacher()
{
	Title = "\0";
	Dept = "\0";
}

Teacher::Teacher(string strName, string strSex, int y, int m, int d, string strTitle, string strDept)
//	:Person(id, strName, strSex, y, m, d), Title(strTitle), Dept(strDept)
{
	SetTeacher(strName, strSex, y, m, d, strTitle, strDept);
}

void Teacher::Display()
{
	Person::Display();
	cout << "ְ�ƣ�" << Title << endl;
	cout << "����ϵ��" << Dept;
}

void Teacher::SetValue()
{
	Person::SetValue();
	cout << "ְ�ƣ�";
	cin >> Title;
	cout << "����ϵ��";
	cin >> Dept;
}

void Teacher::SetTeacher(string strName, string strSex, int y, int m, int d, string strTitle, string strDept)
{
	Person::SetPerson(strName, strSex, y, m, d);
	Title = strTitle;
	Dept = strDept;
}
