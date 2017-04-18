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
	//cout << "--------学生数：" << Person::GetCount() << "--------" << endl;
	//Person *pObj = new Person;
	//pObj->SetValue();                                  //键盘输入
	//pObj->Display();
	//cout << "--------学生数：" << Person::GetCount() << "--------" << endl;
	//delete pObj;
	//cout << "--------学生数：" << Person::GetCount() << "--------" << endl;
	//Person other("王武", "男", 1997, 11, 11);
	//other.Display();
	//cout << "--------学生数：" << Person::GetCount() << "--------" << endl;

	/************************ Experiment 3 ************************/
	//Teacher teach("张山", "男", 1978, 11, 11, "讲师", "计算机系");
	//Student stud;
	//cout << "------------请输入学生信息---------------" << endl;
	//stud.SetValue();  //键盘输入
	//PrintInfo(teach);
	//PrintInfo(stud);

	/************************ Experiment 4 ************************/
	//Teacher teach( "张山", "男", 1978, 11, 11, "讲师", "计算机系");
	//Student stud;
	//cout << "------------请输入学生信息---------------" << endl;
	//cin >> stud;  //键盘输入
	//cout << teach<<endl;
	//cout << stud<<endl;

	/************************ Experiment 5 ************************/
	Teacher teach("张山","男",1978,11,11,"讲师","计算机系");
	Student stud("李世", "男", 1991, 11, 11, "计算机科学", "2010");
	cout << teach << endl;
	cout << stud << endl;
	cout << "是否要保存学生数据到文件（y/n）？";
	char ch;
	cin >> ch;
	if (ch == 'y' || ch == 'Y') {
		ofstream datafile;
		datafile.open("student.txt", ios::out);
		if (!datafile) {
			cout << "\\student．dat文件打开失败！" << endl;
			exit(1);
		}
		else {
			datafile << stud;	//保存stud学生数据到文件
			datafile.close();
			cout << "保存成功！" << endl;
		}
	}
	cout << endl << "是否要读取学生数据文件并显示（y/n）？";
	cin >> ch;
	if (ch == 'y' || ch == 'Y') {
		ifstream datafile;
		datafile.open("student.txt", ios::in);
		if (!datafile) {
			cout << "\\student.txt打开失败" << endl;
			exit(1);
		}
		else {
			cout << "读取数据文件并显示！" << endl;
			Student objStu;
			datafile >> objStu;
			datafile.close();
			cout << objStu;
		}
	}
	system("pause");
}

