#pragma once
#include "Person.h"

class Teacher :public Person {
public:
	Teacher();
	Teacher(int id, string strName, string strSex, int y, int m, int d, string strTitle, string strDept);
	virtual void Display();
	virtual void SetValue();
	void SetTeacher(int id, string strName, string strSex, int y, int m, int d, string strTitle, string strDept);
private:
	string Title;
	string Dept;
};