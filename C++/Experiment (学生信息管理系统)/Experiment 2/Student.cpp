#include "Student.h"

Student::Student()
{
	Major = "\0";
	Grade = "\0";
}

Student::Student(int id, string strName, string strSex, int y, int m, int d, string strMajor, string strGrade)
	//:Person(id, strName,strSex, y, m, d),Major(strMajor),Grade(strGrade)
{
	SetStudent(id, strName, strSex, y, m, d, strMajor, strGrade);
}

void Student::Display()
{
	Person::Display();
	cout << "רҵ��" << Major << endl;
	cout << "�꼶��" << Grade;
}

void Student::SetValue()
{
	Person::SetValue();
	cout << "רҵ��";
	cin >> Major;
	cout << "�꼶��";
	cin >> Grade;
}

void Student::SetStudent(int id, string strName, string strSex, int y, int m, int d, string strMajor, string strGrade)
{
	Person::SetPerson(id, strName, strSex, y, m, d);
	Major = strMajor;
	Grade = strGrade;
}
