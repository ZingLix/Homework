#include "Person.h"
#include "Student.h"
#include "Teacher.h"

void PrintInfo(Person &ob) {
	ob.Display();
	cout << endl;
}

void main() {
	/************************ Experiment 2 ************************/
	//Person obj(1,"����", "��", 1996, 11, 11);
	//obj.Display();
	//cout << "--------ѧ������" << Person::GetCount() << "--------" << endl;
	//Person *pObj = new Person;
	//pObj->SetValue();                                  //��������
	//pObj->Display();
	//cout << "--------ѧ������" << Person::GetCount() << "--------" << endl;
	//delete pObj;
	//cout << "--------ѧ������" << Person::GetCount() << "--------" << endl;
	//Person other(2,"����", "��", 1997, 11, 11);
	//other.Display();
	//cout << "--------ѧ������" << Person::GetCount() << "--------" << endl;

	/************************ Experiment 3 ************************/
	Teacher teach(3,"��ɽ", "��", 1978, 11, 11, "��ʦ", "�����ϵ");
	Student stud;
	cout << "------------������ѧ����Ϣ---------------" << endl;
	stud.SetValue();  //��������
	PrintInfo(teach);
	PrintInfo(stud);

	system("pause");
}

