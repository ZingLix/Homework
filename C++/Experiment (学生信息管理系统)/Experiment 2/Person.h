#pragma once
#include "TDate.h"
#include <string>
#ifndef PERSON
class Person {
public:
	Person();
	Person(string strName, string strSex, int y, int m, int d);
	virtual void Display();
	virtual void SetValue();
	static int GetCount();
	int GetID();
	void SetPerson(string strName, string strSex, int y, int m, int d);
	~Person();

	friend ostream & operator<<(ostream&oo, Person&obj);
	friend istream & operator>>(istream&ii, Person&obj);

private:
	int ID;
	string Name;
	string Sex;
	TDate Birthday;
	static int Count;
};

#endif // !PERSON
