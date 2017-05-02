#pragma once
#include "Person.h"

class Teacher :virtual public Person {
public:
	Teacher();
	Teacher(string strName, string strSex, int y, int m, int d, string strTitle, string strDept);
	virtual void Display();
	virtual void SetValue();
	void SetTeacher(string strName, string strSex, int y, int m, int d, string strTitle, string strDept);
	virtual void ReadFile(ifstream & InFile); //读文件
	virtual void WriteFile(ofstream & OutFile); //文件保存
private:
	string Title;
	string Dept;
};