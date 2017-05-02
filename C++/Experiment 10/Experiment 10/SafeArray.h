#pragma once

#include <iostream>
using namespace std;

template<class T, int size>
class SafeArray {
public:
	SafeArray();
	T& operator[](int i);
	void print();
	void sort();
	int find(T val);
private:
	T arr[size];
};

template<class T, int size>
SafeArray<T, size>::SafeArray() {
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
}

template<class T, int size>
T& SafeArray<T, size>::operator[](int i) {
	if (i < 0 || i >= size) {
		cout << "Out of bound" << endl;
		exit(1);
	}
	else {
		return arr[i];
	}
}

template<class T, int size>
void SafeArray<T, size>::print() {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

template<class T,int size>
void SafeArray<T, size>::sort() {
	int temp;
	for (int j = 0; j < size - 1; j++)
		for (int i = 0; i < size - 1 - j; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
}

template<class T,int size>
int SafeArray<T,size>::find(T val) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == val) return i;
	}
	return -1;
}