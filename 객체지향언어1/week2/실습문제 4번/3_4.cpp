#include <iostream>
using namespace std;

int main() {
	double x[5];
	double sum = 0;
	cout << "실수 5개를 입력하세요";
	for (int i = 0; i < 5; i++) {
		cin >> x[i];
	}

	for (int i = 0; i < 5; i++) {
		if(x[i]>0)
			sum += x[i];
	}

	cout << "양수 합은 " << sum << "입니다.";
}