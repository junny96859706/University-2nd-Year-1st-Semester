#include <iostream>
using namespace std;

int main() {
	int num, a, result;

	while (1) {
		cout << "정수를 입력하세요>>";
		cin >> num;

		a = num % 100;
		result = a / 10;

		cout << num << "의 10자리수는 " << result << "입니다."<< endl;
	}
}