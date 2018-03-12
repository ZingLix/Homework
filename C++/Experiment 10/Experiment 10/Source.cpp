#include "SafeArray.h"
#include <iostream>
int main() {
	SafeArray<int, 5> ais;
	SafeArray<float, 5> afs;
	ais[2] = 3;
	afs[3] = 5.5;
	ais[4] = 2;
	ais.print();
	cout << endl;
	afs.print();
	cout << endl;
	ais.sort();
	ais.print();
	cout << endl << ais.find(2);
	system("pause");
}