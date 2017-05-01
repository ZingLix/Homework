#include <iostream>
using namespace std;

template<class T, int size>
class SafeArray {
public:
	SafeArray() {
		for (int i = 0; i < size; i++) {
			arr[i] = 0;
		}
	}
	T& operator[](int i){
		if (i < 0 || i >= size) {
			cout << "Out of bound"<<endl;
			exit(1);
		}
		else {
			return arr[i];
		}
	}
	void print() {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
	}
private:
	T arr[size];
};

int main() {
	SafeArray<int, 5> ais;
	SafeArray<float, 5> afs;
	ais[2] = 3;
	afs[3] = 5.5;
	ais.print();
	cout << endl;
	afs.print();
	system("pause");
}