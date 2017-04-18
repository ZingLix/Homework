#include "Person.h"
#include "Student.h"
#include "Teacher.h"

void PrintInfo(Person &ob) {
	ob.Display();
	cout << endl;
}

void main() {
	/************************ Experiment 2 ************************/
	//Person obj("zhangsan", "male", 1996, 11, 11);
	//obj.Display();
	//cout << "--------ѧ������" << Person::GetCount() << "--------" << endl;
	//Person *pObj = new Person;
	//pObj->SetValue();                                  //��������
	//pObj->Display();
	//cout << "--------ѧ������" << Person::GetCount() << "--------" << endl;
	//delete pObj;
	//cout << "--------ѧ������" << Person::GetCount() << "--------" << endl;
	//Person other("����", "��", 1997, 11, 11);
	//other.Display();
	//cout << "--------ѧ������" << Person::GetCount() << "--------" << endl;

	/************************ Experiment 3 ************************/
	//Teacher teach("��ɽ", "��", 1978, 11, 11, "��ʦ", "�����ϵ");
	//Student stud;
	//cout << "------------������ѧ����Ϣ---------------" << endl;
	//stud.SetValue();  //��������
	//PrintInfo(teach);
	//PrintInfo(stud);

	/************************ Experiment 4 ************************/
	//Teacher teach( "��ɽ", "��", 1978, 11, 11, "��ʦ", "�����ϵ");
	//Student stud;
	//cout << "------------������ѧ����Ϣ---------------" << endl;
	//cin >> stud;  //��������
	//cout << teach<<endl;
	//cout << stud<<endl;

	/************************ Experiment 5 ************************/
	Teacher teach("��ɽ","��",1978,11,11,"��ʦ","�����ϵ");
	Student stud("����", "��", 1991, 11, 11, "�������ѧ", "2010");
	cout << teach << endl;
	cout << stud << endl;
	cout << "�Ƿ�Ҫ����ѧ�����ݵ��ļ���y/n����";
	char ch;
	cin >> ch;
	if (ch == 'y' || ch == 'Y') {
		ofstream datafile;
		datafile.open("student.txt", ios::out);
		if (!datafile) {
			cout << "\\student��dat�ļ���ʧ�ܣ�" << endl;
			exit(1);
		}
		else {
			datafile << stud;	//����studѧ�����ݵ��ļ�
			datafile.close();
			cout << "����ɹ���" << endl;
		}
	}
	cout << endl << "�Ƿ�Ҫ��ȡѧ�������ļ�����ʾ��y/n����";
	cin >> ch;
	if (ch == 'y' || ch == 'Y') {
		ifstream datafile;
		datafile.open("student.txt", ios::in);
		if (!datafile) {
			cout << "\\student.txt��ʧ��" << endl;
			exit(1);
		}
		else {
			cout << "��ȡ�����ļ�����ʾ��" << endl;
			Student objStu;
			datafile >> objStu;
			datafile.close();
			cout << objStu;
		}
	}
	system("pause");
}

