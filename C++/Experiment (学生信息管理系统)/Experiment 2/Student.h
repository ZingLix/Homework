#pragma once
#include "Person.h"

class Student :public Person {
public:
	Student();
	Student(string strName, string strSex, int y, int m, int d, string strMajor, string strGrade);
	virtual void Display();
	virtual void SetValue();
	void SetStudent(string strName, string strSex, int y, int m, int d, string strMajor, string strGrade);
	virtual void ReadFile(ifstream & InFile); //���ļ�
	virtual void WriteFile(ofstream & OutFile); //�ļ�����
private:
	string Major;
	string Grade;
};