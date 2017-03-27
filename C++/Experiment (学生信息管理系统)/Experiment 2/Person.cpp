#include "Person.h"

int Person::Count = 0;

Person::Person()
{
	ID = 0;
	Name = "\0";
	Sex = "\0";
	Count++;
}

Person::Person(int id,string strName, string strSex, int y, int m, int d)
{
	this->SetPerson(id, strName, strSex, y, m, d);
	Count++;
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
	cout << "ѧ�ţ�";
	cin >> ID;
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

void Person::SetPerson(int id, string strName, string strSex, int y, int m, int d)
{
	ID = id;
	Name = strName;
	Sex = strSex;
	Birthday.SetDate(y, m, d);
}

Person::~Person()
{
	Count--;
}
