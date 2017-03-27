#pragma once
#include "TDate.h"
#include <string>
#ifndef PERSON
class Person {
public:
	Person();
	Person(int id,string strName, string strSex, int y, int m, int d);
	virtual void Display();
	virtual void SetValue();
	static int GetCount();
	int GetID();
	void SetPerson(int id, string strName, string strSex, int y, int m, int d);
	~Person();

private:
	int ID;
	string Name;
	string Sex;
	TDate Birthday;
	static int Count;
};

#endif // !PERSON
