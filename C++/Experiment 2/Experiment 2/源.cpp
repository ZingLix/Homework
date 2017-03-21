#include "Person.h"

void main() {
	Person obj(1,"张三", "男", 1996, 11, 11);
	obj.Display();
	cout << "--------学生数：" << Person::GetCount() << "--------" << endl;
	Person *pObj = new Person;
	pObj->SetValue();                                  //键盘输入
	pObj->Display();
	cout << "--------学生数：" << Person::GetCount() << "--------" << endl;
	delete pObj;
	cout << "--------学生数：" << Person::GetCount() << "--------" << endl;
	Person other(2,"王武", "男", 1997, 11, 11);
	other.Display();
	cout << "--------学生数：" << Person::GetCount() << "--------" << endl;
	int i;
	cin >> i;
	system("pause");
}
