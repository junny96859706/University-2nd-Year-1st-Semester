#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	cout << "*** 구구단 맞추기 퀴즈입니다 ***" << endl;
	srand((unsigned)time(0)); //랜덤 수 발생시키기전에 한번만 호출, seed초기화
	//srand()선언을 while내에 하면 너무빠를시 같은 숫자가 나올수 있음에 주의!!! while밖에 선언한다.

	int fault = 0;

	while (1) {
		int num1 = rand() % 9 + 1;
		int num2 = rand() % 9 + 1;

		int result = 0;

		cout << num1 << "x" << num2 << "=";
		cin >> result;
		if (num1 * num2 == result) {
			cout << "정답입니다. 잘했습니다" << endl;
		}
		else {
			fault++;
			if (fault == 3) {
				cout << "3번 틀렸습니다. 퀴즈를 종료합니다.";
				break;
			}
			cout << fault << "번 틀렸습니다." << "분발하세요." << endl;
		}
	}
}