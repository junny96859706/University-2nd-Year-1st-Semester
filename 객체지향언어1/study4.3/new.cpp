#include <iostream>
using namespace std;

int main() {
	int n;
	int* p;
	cout << "몇개입력>>";
	cin >> n;
	p = new int[n];
	if (p == NULL) {
		cout << "할당실패";
		return 0; //exit(0);
	}

	for (int i = 0; i < n; i++) {
		cout << (i + 1) << "번쩨 정수: ";
		cin >> p[i]; //*(p+1);
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += p[i];
	}

	cout << sum / n;
	delete[] p;
}