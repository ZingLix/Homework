#include "Student.h"

Student::Student()
{
	Major = "\0";
	Grade = "\0";
}

Student::Student(string strName, string strSex, int y, int m, int d, string strMajor, string strGrade)
	:Person(strName,strSex, y, m, d),Major(strMajor),Grade(strGrade)
{
//	SetStudent(strName, strSex, y, m, d, strMajor, strGrade);
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

void Student::SetStudent(string strName, string strSex, int y, int m, int d, string strMajor, string strGrade)
{
	Person::SetPerson(strName, strSex, y, m, d);
	Major = strMajor;
	Grade = strGrade;
}

void Student::ReadFile(ifstream & InFile)
{
	Person::ReadFile(InFile);
	InFile >> Major >> Grade;
}

void Student::WriteFile(ofstream & OutFile)
{
	Person::WriteFile(OutFile);
	OutFile << Major << " " << Grade;
}
