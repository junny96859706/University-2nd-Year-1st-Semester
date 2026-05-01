#include <iostream>
using namespace std;


int main() {
	int n;
	int sum = 0;
	cout << "입력할 정수의 개수는?";
	cin >> n;

	int* p = new int[n];
	if (!p) {
		cout << "메모리 부족";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cout << i+1 << "번째 정수:";
		cin >> p[i];
	}

	for (int j = 0; j < n; j++) {
		sum += p[j];
	}

	int average = sum / n;
	cout << "평균 =" << average << endl;

	delete[] p;
	return 0;

}