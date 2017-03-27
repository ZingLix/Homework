#include "Person.h"
#include "Student.h"
#include "Teacher.h"

void PrintInfo(Person &ob) {
	ob.Display();
	cout << endl;
}

void main() {
	/************************ Experiment 2 ************************/
	//Person obj(1,"张三", "男", 1996, 11, 11);
	//obj.Display();
	//cout << "--------学生数：" << Person::GetCount() << "--------" << endl;
	//Person *pObj = new Person;
	//pObj->SetValue();                                  //键盘输入
	//pObj->Display();
	//cout << "--------学生数：" << Person::GetCount() << "--------" << endl;
	//delete pObj;
	//cout << "--------学生数：" << Person::GetCount() << "--------" << endl;
	//Person other(2,"王武", "男", 1997, 11, 11);
	//other.Display();
	//cout << "--------学生数：" << Person::GetCount() << "--------" << endl;

	/************************ Experiment 3 ************************/
	Teacher teach(3,"张山", "男", 1978, 11, 11, "讲师", "计算机系");
	Student stud;
	cout << "------------请输入学生信息---------------" << endl;
	stud.SetValue();  //键盘输入
	PrintInfo(teach);
	PrintInfo(stud);

	system("pause");
}

