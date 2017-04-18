#include "Person.h"

int Person::Count = 0;

Person::Person()
{
	ID = 0;
	Name = "\0";
	Sex = "\0";
	ID=++Count;
}

Person::Person(string strName, string strSex, int y, int m, int d)
{
	this->SetPerson(strName, strSex, y, m, d);
	ID=++Count;
}

void Person::Display()
{
	cout << "��ţ�" << ID << endl;
	cout << "������" << Name << endl;
	cout << "�Ա�" << Sex << endl;
	cout << "�������ڣ�";
	Birthday.Display();
	cout << endl;

}

void Person::SetValue()
{
//	cout << "ѧ�ţ�";
//  cin >> ID;
	cout << "������";
	cin >> Name;
	cout << "�Ա�";
	cin >> Sex;
	Birthday.SetValue();
}

int Person::GetCount()
{
	return Count;
}

int Person::GetID()
{
	return ID;
}

void Person::SetPerson(string strName, string strSex, int y, int m, int d)
{
	Name = strName;
	Sex = strSex;
	Birthday.SetDate(y, m, d);
}

Person::~Person()
{
	Count--;
}

void Person::ReadFile(ifstream & InFile)
{
	InFile>>ID >> Name >> Sex;
	Birthday.ReadFile(InFile);
}

void Person::WriteFile(ofstream & OutFile)
{
	OutFile << ID << " " << Name << " " << Sex << " ";
	Birthday.WriteFile(OutFile);
}

ostream & operator<<(ostream & oo, Person & obj)
{
	obj.Display();
	return oo;
	// TODO: �ڴ˴����� return ���
}

istream & operator>>(istream & ii, Person & obj)
{
	obj.SetValue();
	return ii;
	// TODO: �ڴ˴����� return ���
}

ofstream & operator<<(ofstream & strefile, Person & obj)
{
	obj.WriteFile(strefile);
	strefile << endl;
	return strefile;
	// TODO: insert return statement here
}

ifstream & operator>>(ifstream & strefile, Person & obj)
{
	obj.ReadFile(strefile);
	return strefile;
	// TODO: insert return statement here
}
