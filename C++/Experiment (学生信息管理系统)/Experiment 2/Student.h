#pragma once
#include "Person.h"

class Student :public Person {
public:
	Student();
	Student(string strName, string strSex, int y, int m, int d, string strMajor, string strGrade);
	virtual void Display();
	virtual void SetValue();
	void SetStudent(string strName, string strSex, int y, int m, int d, string strMajor, string strGrade);
private:
	string Major;
	string Grade;
};