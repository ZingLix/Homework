//HDU 3743
#include <iostream>
#include <memory>
#include <cstring>

int data[1000001];
int aux[1000001];
long long int res;

void merge(int data[], int l, int mid, int h) {
	int length = h - l + 1;
	if (length <= 1) return;
	memcpy(aux+l, data+l, length * sizeof(int));
	int it1 = l, it2 = mid + 1, i = l;
	for (; it1 <= mid && it2 <= h; ++i) {
		if (aux[it1] > aux[it2]) {
			data[i] = aux[it2++];
			res += mid - it1 + 1;
		}
		else {
			data[i] = aux[it1++];
		}
	}
	while (it1 <= mid) data[i++] = aux[it1++];
	while (it2 <= h) data[i++] = aux[it2++];
}

void sort(int data[], int l, int h) {
	if (l >= h) return;
	int mid = (l + h) / 2;
	sort(data, l, mid);
	sort(data, mid + 1, h);
	merge(data, l, mid, h);
}

int main() {
	int n;
	while (std::cin >> n) {
		std::memset(data, 0, sizeof(data));
		std::memset(aux, 0, sizeof(aux));
		int i = 0;
		while (n--) std::cin >> data[i++];
		res = 0;
		sort(data, 0, i - 1);
		std::cout << res <<std::endl;
	}
}