#include "Person.h"

void main() {
	Person obj(1,"����", "��", 1996, 11, 11);
	obj.Display();
	cout << "--------ѧ������" << Person::GetCount() << "--------" << endl;
	Person *pObj = new Person;
	pObj->SetValue();                                  //��������
	pObj->Display();
	cout << "--------ѧ������" << Person::GetCount() << "--------" << endl;
	delete pObj;
	cout << "--------ѧ������" << Person::GetCount() << "--------" << endl;
	Person other(2,"����", "��", 1997, 11, 11);
	other.Display();
	cout << "--------ѧ������" << Person::GetCount() << "--------" << endl;
	int i;
	cin >> i;
	system("pause");
}
